#include<bits/stdc++.h>
using namespace std;

const int maxn = 510;
int dp[maxn][maxn][2],d[maxn],tot[maxn],n;
vector<int> G[maxn];

void dfs(int u){
    tot[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        dfs(v);
        tot[u]+=tot[v];
    }
    dp[u][1][0] = dp[u][1][1] = 0;
    for(int i=2;i<=tot[u];i++){
        dp[u][i][0] = dp[u][i][1] = 1e9;
    }
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        for(int j=tot[u];j>=2;j--){//枚举下u下一共多少个节点，2是因为包括u，v在内
            for(int k=1;k<=tot[v];k++){//枚举走v一下走了多少个节点，从1开始是因为v已经在内
                dp[u][j][0] = min(dp[u][j][0],dp[u][j-k][0]+dp[v][k][0]+2*d[v]);
                dp[u][j][1] = min(dp[u][j][1],dp[u][j-k][0]+dp[v][k][1]+d[v]);
                dp[u][j][1] = min(dp[u][j][1],dp[u][j-k][1]+dp[v][k][0]+2*d[v]);
            }
        }
    }
}

int main(){
    int kase = 0;
    while(scanf("%d",&n)&&n){
        for(int i=0;i<=n;i++)G[i].clear();
        memset(tot,0,sizeof(tot));
        memset(dp,0,sizeof(dp));
        memset(d,0,sizeof(d));
        for(int i=1;i<=n-1;i++){
            int u,v,w;
            scanf("%d%d%d",&v,&u,&w);
            G[u].push_back(v);//做成有向图是为了方便防止父子节点来回走
            d[v] = w;
        }
        dfs(0);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++kase);
        while(q--){
            int k;
            scanf("%d",&k);
        int ans = 0;
        for(int i=n;i>=1;i--){
            if(k>=dp[0][i][1])
            {
                ans = i;
                break;
            }
        }
        printf("%d\n",ans);
        }
    }
    return 0;
}
//20220330
#include<bits/stdc++.h>
using namespace std;
vector<int> G[1050];
long long dp[1050][2];

void dfs(int u, int pa) {
    dp[u][0] = dp[u][1] = 0;
  

    for(int i=0; i< G[u].size();i++){
        int v = G[u][i];
        if(v == pa)
            continue;
        dfs(v, u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
    dp[u][1] ++;
}
int main() {
    int n, y;
    while(cin>> n && n) {
        for(int i = 1; i <= n; i++)
            G[i].clear();
  
        for(int i = 1; i <= n; i++) {
            int k, v;
            cin>> k;
            while(k--) {
                cin>> v;
                G[i].push_back(v);
            }
        }
        if(n==1){
            puts("1");
            continue;
        }

        dfs(1, -1);
    
        printf("%lld\n", min(dp[1][0], dp[1][1]));
    }
    return 0;
}
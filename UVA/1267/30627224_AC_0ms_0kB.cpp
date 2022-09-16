#include<bits/stdc++.h>
using namespace std;
vector<int> G[1050], node[1050];
int n, s, k, p[1050];
bool used[1050];

void dfs1(int u, int f, int dist){
    p[u] = f;
    int nd = G[u].size();

    if(nd == 1 && dist > k)
        node[dist].push_back(u);

    for(int i=0;i < nd; i++){
        int v = G[u][i];
        if(v != f)
            dfs1(v, u, dist + 1);
    }
}
void dfs2(int u, int f, int d){
    used[u] = true;
    int nd = G[u].size();
    for (int i = 0; i < nd; ++i)
    {
        int v = G[u][i];
        if(v != f && d < k)
            dfs2(v, u, d+1);
    }
}
int solve(){
    int ans = 0;

    for(int dist = (n-1); dist > k; dist--){
        for(int i=0; i<node[dist].size(); i++){
            int u = node[dist][i];
            if(used[u])
                continue;
            int v = u;
            for(int j=0;j<k;j++)
                v = p[v];
            dfs2(v, -1, 0);
            ans++;
        }
    }
    return ans;
}
int main() {
    int t;
    cin>> t;
    while (t--) {
        memset(used, 0, sizeof(used));

        cin>> n>> s>> k;
        for (int i = 0; i <= n; i++){
            G[i].clear();
            node[i].clear();
        }
        int x, y;
        for (int i = 1; i < n; i++) {
            cin>> x>> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        dfs1(s, -1, 0);
        printf("%d\n", solve());        

    }
    return 0;
}
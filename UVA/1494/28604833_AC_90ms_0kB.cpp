#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int u;
	int v;
	int cost;
	bool operator<(const Edge &rhs) const{
		return cost < rhs.cost;
	}
};

int x[1050],y[1050],p[1050];
int dp[1050][1050];
vector<Edge> G[1050], edge;
vector<int> visited;
int fa[1050];
double sum ;
int dis(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}
int findroo(int x){
	if(fa[x] == x)
		return x;
	fa[x] = findroo(fa[x]);
	return fa[x];
}
void dfs(int u,int v,int w){
	for(int i : visited)
		dp[i][v] = dp[v][i] = max(dp[i][u], w);

	visited.push_back(v);
	for(int i=0;i<G[v].size();i++){
		int next_v = G[v][i].v;
		if(next_v == u)
			continue;
		dfs(v, next_v, G[v][i].cost);
	}
}
int main(){
    int t;
    cin>> t;
    while(t--){
    	edge.clear();
    	sum = 0.0;
    	int n;
    	cin>> n;
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=n;j++)
    			dp[i][j] = 0.0;
    	for(int i=1;i<=n;i++){
    		G[i].clear();
    		fa[i] = i;
    		cin>> x[i]>> y[i]>> p[i];
    	}
    	for(int i=1;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
    			edge.push_back(Edge{i, j, dis(i,j)});
    		}
    	}
    	sort(edge.begin(),edge.end());

    	int line = 0;
    	for(int i=0;i<edge.size();i++){
    		while(findroo(edge[i].u) == findroo(edge[i].v))
    			i++;
    		int u = edge[i].u;
    		int v = edge[i].v;
    		fa[findroo(v)] = findroo(u);
    		sum += sqrt(edge[i].cost);
    		G[u].push_back(Edge{u, v, edge[i].cost});
    		G[v].push_back(Edge{v, u, edge[i].cost});
    		line++;
    		if(line == n-1)
    			break; 
    	}
    	visited.clear();
    	dfs(-1,1,0);
    	
    	double ans = 0;
    	for(int i=1;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
    			ans = max(ans, (p[i] + p[j])/(sum - sqrt(dp[i][j])));
    		}
    	}
    	printf("%.2lf\n", ans);
    }
    return 0;
}
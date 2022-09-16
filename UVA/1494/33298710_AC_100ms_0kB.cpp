#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u;
	int v;
	double cost;
	bool operator<(const Edge &rhs) const{
		return cost < rhs.cost;
	}
};
int x[1050], y[1050], p[1050], fa[1050];
double dp[1050][1050];
vector<Edge> edge;
vector<Edge> G[1050];
vector<int> visited;
int n;
double sum = 0.0;
int findroo(int x){
	if(fa[x] == x)
		return x;
	return fa[x] = findroo(fa[x]);
}
double dist(int i, int j){
	double a = (x[i] - x[j]) * (x[i] - x[j]);
	double b = (y[i] - y[j]) * (y[i] - y[j]);
	return sqrt( a +  b);
}


void build(){
	int line = 0;
	for(int i=0; i<edge.size();i++){
		while(findroo(edge[i].u) == findroo(edge[i].v))
			i++;
		int u = edge[i].u;
		int v = edge[i].v;
		fa[findroo(v)] = findroo(u);
		G[u].push_back( Edge{u, v, edge[i].cost});
		G[v].push_back( Edge{v, u, edge[i].cost});
		sum += edge[i].cost;
		line++;
		if(line == n-1)
			break;
	}
}
void dfs(int u, int v, double w){
	for(auto i : visited){
		dp[i][v] = dp[v][i] = max(dp[i][u], w);
	}
	visited.push_back(v);
	for(int i=0; i<G[v].size(); i++){
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
		cin>> n;
		sum = 0.0;
		for(int i=0; i<n;i++)
			for(int j=0; j<n; j++)
				dp[i][j] = 0.0;
		
		edge.clear();
		for(int i=0;i<n;i++){
			fa[i] = i;
			G[i].clear();
			cin>> x[i]>> y[i]>> p[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				edge.push_back(Edge{i, j, dist(i, j)});
			}
		}
		sort(edge.begin(), edge.end());
		build();
		visited.clear();
		dfs(-1, 1, 0.0);
		double ans = 0.0;
	
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans = max(ans, (double)(p[i] + p[j])/( sum - dp[i][j]));
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
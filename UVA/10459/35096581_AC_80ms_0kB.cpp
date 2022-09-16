#include<bits/stdc++.h>
using namespace std;
vector<int> G[5050];
int dis[5050];
int maxx;
void dfs(int u, int v, int d){
	dis[v] = max( dis[v], d);
	maxx = max(dis[v], maxx);
	for(int i : G[v]){
		if(i != u)
			dfs(v, i, d+1); 
	}
	return ;
}
int main(){
	int n;
	while(cin>> n){
		for(int i=1; i<=n; i++){
			G[i].clear();
			dis[i] = 0;
			int t;
			cin>> t;
			while(t--){
				int x;
				cin>> x;
				G[i].emplace_back(x);
			}
		}
		maxx = 0;
		dfs(-1, 1, 0);
		set<int> worst, best;
		for(int i=1; i<=n; i++)
			if(dis[i] == maxx)
				worst.insert(i);
		dfs(-1, *worst.begin(), 0);
		int leaf;
		for(int i=1; i<=n; i++){
			if(dis[i] == maxx){
				leaf = i;
				worst.insert(i);
			}
		}
		dfs(-1, leaf, 0);
		for(int i=1; i<=n; i++){
			if(maxx % 2 && dis[i] == maxx / 2 + 1)
				best.insert(i);
			else if(maxx % 2 == 0 && dis[i] == maxx / 2)
				best.insert(i);
		}
		
		cout<< "Best Roots  :";
		for(int i : best)
			cout<<" "<< i;
		cout<< endl;
		cout<< "Worst Roots :";
		for(int i : worst)
			cout<<" "<< i;
		cout<< endl;
	}
	return 0; 
}
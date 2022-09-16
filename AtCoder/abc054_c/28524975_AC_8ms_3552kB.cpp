#include<bits/stdc++.h>
using namespace std;
int m, n;
vector<int> G[10];
int sum;
bool vis[10];
void dfs(int x, int used){
	vis[x] = true;
	if(used == n){
		sum++;
		vis[x] = false;
		return;
	}
	for(int i=0;i<G[x].size();i++){
		if(!vis[G[x][i]])
			dfs(G[x][i], used+1);
	}
	vis[x] = false;
	return;
}
int main(){
	while(cin>> n>> m){
		int a, b;
		sum = 0;
		for(int i=0;i<=n;i++){
			vis[i] = false;
			G[i].clear();
		}

		for(int i=0; i<m; i++){
			cin>> a>> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(1 , 1);
		cout<<sum<<endl;
	}
	return 0;
}
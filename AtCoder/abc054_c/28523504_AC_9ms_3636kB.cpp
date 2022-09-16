#include<bits/stdc++.h>
using namespace std;
int m, n;
vector<int> G[10];
bool used[10];
int sum;

bool check(){
	for(int i=1;i<=n;i++){
		if(!used[i])
			return false;
	}
	return true;
}
void dfs(int x){
	used[x] = true;
	if(check()){
		sum++;
		used[x] = false;
		return;
	}
	for(int i=0;i<G[x].size();i++){
		if(!used[G[x][i]])
			dfs(G[x][i]);
	}
	used[x] = false;
	return;
}
int main(){
	while(cin>> n>> m){
		int a, b;
		sum = 0;
		for(int i=0;i<=n;i++){
			used[i] = false;
			G[i].clear();
		}
		for(int i=0; i<m; i++){
			cin>> a>> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(1);
		cout<<sum<<endl;
	}
	return 0;
}
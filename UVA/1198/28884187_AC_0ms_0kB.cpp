#include <bits/stdc++.h>
using namespace std;
int maze[45][45];
int node;
bool used[45];
void goo(int u, int v){
	used[u] = true;
	if(u==v)
		return;
	for(int i=1;i<=node;i++)
		if(maze[u][i] ==1 && maze[i][v] == maze[u][v]-1)
			goo(i,v);
}
int main(){
	while(cin>> node){
		for(int i=0;i<=node;i++){
			for(int j=0;j<=node;j++){
				if(j!=i)
					maze[i][j] = 1e3;
				else
					maze[i][j] = 0;
			}
		}
		int go;
		char hold;
		for(int i=1;i<=node;i++){
			while(cin>> go){
				scanf("%c",&hold);
				maze[i][go] = maze[go][i] = 1;
				if(hold == '\n')
					break;
			}
		}
		for(int mid = 1; mid<=node;mid++){
			for(int i=1;i<=node;i++){
				for(int j=1;j<=node;j++){
					maze[i][j] = min(maze[i][j], maze[i][mid]+maze[mid][j]);
				}
			}
			
		}
		int query;
		cin>> query;
		while(query--){
			memset(used, 0, sizeof(used));
			vector<int> sset;
			while(cin>> go){
				scanf("%c",&hold);
				sset.push_back(go);
				if(hold == '\n')
					break;
			}

			for(int u = 0;u < sset.size();u++){
				for(int v = 0; v<sset.size();v++){
					if(u==v)
						continue;
					goo(sset[u],sset[v]);
				}
			}
			bool flag = true;
			for(int i=1;i<=node;i++)
				if(!used[i]){
					flag = false;
					break;
				}
			if(flag)
				puts("yes");
			else
				puts("no");
		}
	}
}
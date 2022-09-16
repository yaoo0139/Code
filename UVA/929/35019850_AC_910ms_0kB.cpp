#include<bits/stdc++.h>
using namespace std;
int dir[4][2] = {1,0,0,1,0,-1,-1,0};
int arr[1005][1005];
int dis[1005][1005];
int m, n;
struct node{
	int i;
	int j;
	int w;
	bool operator<(const node &rhs) const{
		return w > rhs.w;
	}
};
void dijkstra(int si, int sj){
	dis[si][sj] = arr[si][sj];
	priority_queue<node> pq;
	pq.push(node{si, sj, 0});
	while(!pq.empty()){
		node now = pq.top();
		pq.pop();
		for(int i=0; i<4; i++){

			if(0 >= now.i + dir[i][0] || now.i + dir[i][0] > m)
				continue;
			if(0 >= now.j + dir[i][1] || now.j + dir[i][1] > n)
				continue;
			if(dis[now.i][now.j] + arr[now.i + dir[i][0]][now.j + dir[i][1]] < dis[now.i + dir[i][0]][now.j + dir[i][1]]){
				dis[now.i + dir[i][0]][now.j + dir[i][1]] = dis[now.i][now.j] + arr[now.i + dir[i][0]][now.j + dir[i][1]];
				pq.push(node{now.i + dir[i][0], now.j + dir[i][1], dis[now.i + dir[i][0]][now.j + dir[i][1]]});
			}
		}
	}
	return ;
}
int main(){
	int t;
	cin>> t;
	while(t--){

		cin>> m>> n;
		for(int i=0; i<=1000; i++)
			dis[i][0] = dis[0][i] = arr[i][0] = arr[0][i] = arr[m+1][i] = arr[i][n+1] = 1e7;
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				cin>> arr[i][j];
				dis[i][j] = 1e7;
			}
		}
		dijkstra(1, 1);
		cout<< dis[m][n]<< endl;;
	}
	return 0;
}
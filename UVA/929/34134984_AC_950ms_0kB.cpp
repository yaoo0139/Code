#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int maze[1005][1005];
int mv[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}};
struct node
{
	int x;
	int y;
	int cost;
	bool operator<(const node &rhs)const{
		return cost > rhs.cost;
	}
};
int main(){
	int T;
	cin>> T;
	while(T--){
		int m, n;
		cin>> m>> n;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>> maze[j][i];
				dp[j][i] = 20000;
			}
		}
		priority_queue<node> pq;
		pq.push(node{0, 0, maze[0][0]});
		dp[0][0] = maze[0][0];
		while(!pq.empty()){
			node now = pq.top();
			pq.pop();
			for(int i=0;i<4;i++){
				if(now.x + mv[i][0] < 0 || now.x + mv[i][0] >= n)
					continue;
				if(now.y + mv[i][1] < 0 || now.y + mv[i][1] >= m)
					continue;
				if(dp[now.x + mv[i][0]][now.y + mv[i][1]] > dp[now.x][now.y] + maze[now.x + mv[i][0]][now.y + mv[i][1]]){
					node tmp;
					tmp.cost = dp[now.x + mv[i][0]][now.y + mv[i][1]] = dp[now.x][now.y] + maze[now.x + mv[i][0]][now.y + mv[i][1]];
					tmp.x = now.x + mv[i][0];
					tmp.y = now.y + mv[i][1];
					pq.push(tmp);
				}
			}
		}
		cout << dp[n-1][m-1] << endl;
	}
    return 0;
}
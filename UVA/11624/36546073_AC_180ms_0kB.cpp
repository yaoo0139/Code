#include<bits/stdc++.h>
using namespace std;
int arr[1005][1005];
string maze[1005];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int n, m;
struct node{
    int x;
    int y;
    bool person;
    int dis;
};
int bfs(){
    node s;
    queue<node> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maze[i][j] == 'J')
                s = {i,j,1,0};
            if(maze[i][j] == 'F')
                q.push(node{i,j,0,0});
        }
    }
    q.push(s);
    arr[s.x][s.y] = 0;
    while(!q.empty()){
        node temp = q.front();
        q.pop();
        if (temp.person && (temp.x == 0 || temp.x == n-1 || temp.y == 0 || temp.y == m-1))
            return arr[temp.x][temp.y];
        for(int k=0; k<4; k++){
            int vx = temp.x + dir[k][0], vy = temp.y + dir[k][1];
            if (vx >= 0 && vx < n && vy >= 0 && vy < m && maze[vx][vy]=='.' && arr[vx][vy] == -1){
                arr[vx][vy] = temp.dis + 1;
                q.push(node{vx, vy, temp.person, arr[vx][vy]});
            }
        }
    }
    return -1;
}
int main(){
    int t;
    cin>> t;
    while(t--){
        memset(arr, -1, sizeof(arr));
        cin>> n>> m;
        for(int i=0; i<n; i++)
            cin>> maze[i];
        int sum = bfs();
        if(sum == -1)
            puts("IMPOSSIBLE");
        else
            cout<< sum+1<< endl;
    }
}
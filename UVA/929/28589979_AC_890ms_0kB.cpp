#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
int maze[MAX][MAX],dp[MAX][MAX];
bool v[MAX][MAX];
int mv[4][2]= {{1,0},{0,-1},{-1,0},{0,1}};
typedef struct node
{
    int x,y;
    int dis;
    bool operator<(const node& mynode) const
    {
        return (mynode.dis < dis);
    }
} Node;
int main()
{
    int ncase,n,m;
    priority_queue <Node> pq;
    Node mynode;
    cin >> ncase;
    for(int m=0; m<ncase; m++)
    {
        while (cin >> n >> m)
        {
            memset(v,0,sizeof(v));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){   
                    dp[i][j]=20000;          
                }
            }
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    cin >> maze[i][j];
                }
            }
            mynode.x=0;
            mynode.y=0;
            dp[0][0] = mynode.dis = maze[0][0];
            pq.push(mynode);
            while(!pq.empty())
            {
                mynode=pq.top();
                pq.pop();
                v[mynode.y][mynode.x] = true;
                for(int i=0; i<4; i++)
                {
                    Node tmp;
                    if (((mynode.x+mv[i][0])<0)||((mynode.x+mv[i][0])>=m))
                        continue;
                    if (((mynode.y+mv[i][1])<0)||((mynode.y+mv[i][1])>=n))
                        continue;
                    if (v[mynode.y+mv[i][1]][mynode.x+mv[i][0]] == false)
                    {
                        if (dp[mynode.y+mv[i][1]][mynode.x+mv[i][0]] > (dp[mynode.y][mynode.x] + maze[mynode.y+mv[i][1]][mynode.x+mv[i][0]]))
                        {
                            dp[mynode.y+mv[i][1]][mynode.x+mv[i][0]] = (dp[mynode.y][mynode.x] + maze[mynode.y+mv[i][1]][mynode.x+mv[i][0]]);
                            tmp.x = mynode.x+mv[i][0];
                            tmp.y = mynode.y+mv[i][1];
                            tmp.dis = dp[mynode.y+mv[i][1]][mynode.x+mv[i][0]];
                            pq.push(tmp);
                        }
                    }
                }
                // for(int i=0;i<n;i++){
                //     for(int j=0;j<m;j++){   
                //        cout<<dp[i][j]<<" ";        
                //     }
                //     cout<<endl;
                // }
            }
            cout << dp[n-1][m-1] << endl;
        }
       
    }
    return 0;
}

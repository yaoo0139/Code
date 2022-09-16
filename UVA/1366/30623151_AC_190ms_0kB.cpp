#include<bits/stdc++.h>
using namespace std;
int arr[505][505], a[505][505], b[505][505], dp[505][505];
int main()
{
   
	int n, m;
    while(cin>> n>> m ){
        if(!n && !m)
            break;
        for(int y=1;y<=n;y++){
            for(int x=1;x<=m;x++){
                cin>> arr[x][y];
                a[x][y] = a[x-1][y] + arr[x][y];
            }
        }
        for(int y=1;y<=n;y++){
            for(int x=1;x<=m;x++){
                cin>> arr[x][y];
                b[x][y] = b[x][y-1] + arr[x][y];
            }
        }
        for(int y=1;y<=n;y++){
            for(int x=1;x<=m;x++){
                dp[x][y] = max( dp[x-1][y] + b[x][y], dp[x][y-1] + a[x][y]);
            }
        }

        cout<<dp[m][n]<<endl;

    }
   	return 0;
}
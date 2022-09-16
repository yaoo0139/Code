#include <bits/stdc++.h>
using namespace std;
long long dp[205][205][2];
struct node
{
    long long arr;
    long long cost;

};
node a[205], b[205];

int main(){
    int t;
    cin>> t;
    while(t--){
        int orz;
        int n = 0, m = 0;
        cin>> orz;
        for (int i = 0; i < orz; ++i){
            char c;
            int x, y;
            cin>> c>> x>> y;
            if(c == 'A')
                a[++n] = node{x, y};
            else
                b[++m] = node{x, y};
        }
        for (int i = 0; i <= n; ++i){
            for (int j = 0; j <= m; ++j){
                dp[i][j][0] = dp[i][j][1] = 1e16;
            }
        }

        dp[0][0][1] = dp[0][0][0] = 0;
        for (int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                long long t1 = dp[i][j][0], t2 = 0;
                for(int k = j + 1; k <= m; k++){
                    t1 = max(t1, b[k].arr);
                    t2 = max(t2, t1 + b[k].cost);
                    dp[i][k][1] = min(dp[i][k][1], t2);
                    t1 += 10;
                    t2 += 10;
                }
                t1 = dp[i][j][1], t2 = 0;
                for(int k = i + 1; k <= n; k++){
                    t1 = max(t1, a[k].arr);
                    t2 = max(t2, t1 + a[k].cost);
                    dp[k][j][0] = min(dp[k][j][0], t2);
                    t1 += 10;
                    t2 += 10;
                }
            }
        }
        cout<< min(dp[n][m][1], dp[n][m][0])<<endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main(){
    int L;
    while(cin>> L && L){
        for(int i=0; i<=1000; i++)
            for(int j=i; j<=1000; j++)
                dp[i][j] = 1e9;
        int n;
        cin>> n;
        vector<int> v(n+2);
        v[0] = 0;
        v[n+1] = L;
        for(int i=1; i<=n ;i++){
            cin>> v[i];
            dp[v[i-1]][v[i]] = 0;
        }
        dp[v[n]][v[n+1]] = 0;
        n += 2;
        for(int k=2; k<n; k++){
            for(int i=0; i+k<n; i++){
                for(int j=i+1; j<i+k; j++){
                    dp[v[i]][v[i+k]] = min(dp[v[i]][v[i+k]], dp[v[i]][v[j]] + dp[v[j]][v[i+k]]  + v[i+k] - v[i]);
                    // cout<< v[i]<<" "<< v[i+k]<< " " <<dp[v[i]][v[i+k]]<< endl;
                }
            }
        }
        printf("The minimum cutting is %d.\n", dp[0][L]);
    }
}
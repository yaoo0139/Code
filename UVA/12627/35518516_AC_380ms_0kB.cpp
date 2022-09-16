#include<bits/stdc++.h>
using namespace std;
long long dp[35][1050][1050];
long long sol(int k, int a, int b){
    if(k == 0)
        return 1;

    if(b <= 1024 && dp[k][a][b])
        return dp[k][a][b];

    int sz = 1;
    for(int i=0; i<k; i++)
        sz *= 2;

    if(b <= sz / 2){
        if(b <= 1024)
            return dp[k][a][b] = 2 * sol(k-1, a, b);
        else
            return 2 * sol(k-1, a, b);
    }
    else if(a > sz / 2){
        if(b <= 1024)
            return dp[k][a][b] = sol(k-1, a - sz / 2, b - sz / 2);
        else
            return sol(k-1, a - sz / 2, b - sz / 2);
    }
    else{
        if(b <= 1024)
            return dp[k][a][b] =  2 * sol(k-1, a, sz / 2) + sol(k-1, 1, b - sz / 2);
        else
            return 2 * sol(k-1, a, sz / 2) + sol(k-1, 1, b - sz / 2);
    }
}
int main(){
    int t;
    cin>> t;
    int k, a, b;
    for(int i=1; i<=t; i++){
        cin>> k>> a>> b;
        printf("Case %d: %lld\n", i, sol(k,a,b));
    }
    return 0;
}
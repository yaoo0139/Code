#include<bits/stdc++.h>
using namespace std;
long long dp[35];
long long sol(int k, int r){
    if(r == 0)
        return 0;
    if(k == 0)
        return 1;

    int sz = 1;
    for(int i=0; i<k; i++)
        sz *= 2;
    
    if(r > sz / 2)
        return 2 * dp[k-1] + sol(k-1, r - sz / 2);
    else
        return  2 * sol(k-1, r);
}
int main(){ 
    int t;
    cin>> t;
    int k, a, b;
    dp[0] = 1;
    for(int i=1; i<31; i++)
        dp[i] = 3 * dp[i-1];
    for(int i=1; i<=t; i++){
        cin>> k>> a>> b;
        printf("Case %d: %lld\n", i, sol(k, b) - sol(k, a - 1));
    }
    return 0;
}
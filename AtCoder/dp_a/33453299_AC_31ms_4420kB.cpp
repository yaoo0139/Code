#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100500];
    int dp[100500] = {0};
    int n;
    while(cin>> n){
        cin>> arr[1];
        arr[0] = arr[1];
        for(int i=2; i<=n;i++){
            cin>> arr[i];
            dp[i] = min(abs(arr[i] - arr[i-1]) + dp[i-1], abs(arr[i] - arr[i-2]) + dp[i-2]);
        }
        cout<< dp[n]<< endl;
    }
    return 0;
}
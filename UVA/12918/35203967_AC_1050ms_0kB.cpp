#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        int n, m;
        cin>> n>> m;
        long long ans = 0;
        for(long long i = m - 1, counter = 0; counter<n; counter++, i--)
            ans += i;
        cout<< ans<< endl;
    }       
    return 0;
}
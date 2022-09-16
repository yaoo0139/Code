#include<bits/stdc++.h>
using namespace std;
int josephus(int n, int k){
    return n > 1 ? (josephus(n-1, k) + k) % n : 0;
}
int main(){
    int n, k, m;
    while(cin>> n>> k>> m){
        if(!n && !k && !m )
            break;
        int ans = (josephus( n-1, k) + (m + 1) % n) % n;
        if(ans == 0)
            ans = n;
        cout<< ans<< endl;

    }
    return 0;
}

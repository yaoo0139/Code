#include<bits/stdc++.h>
using namespace std;
int josephus(int n, int k){
    return n > 1 ? (josephus(n-1, k) + k) % n : 0;
}
int main(){
    int n, k, m;
    while(cin>> n>> k>> m && (n || k || m))
        cout<< (josephus( n-1, k) + m) % n + 1<< endl;
    return 0;
}

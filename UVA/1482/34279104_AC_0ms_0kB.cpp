//20211222
#include<bits/stdc++.h>
using namespace std;
long long sg(long long x){
    return x%2==0?x/2:sg(x/2);
}
int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        long long a;
        cin>> a;
        a = sg(a);
        n--;
        while(n--){
            long long x;
            cin>> x;
            a = a^sg(x);
        }
        cout<< (a?"YES\n":"NO\n");
    }
    return 0;
}
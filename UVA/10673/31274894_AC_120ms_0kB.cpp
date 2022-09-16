#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    while(n--){
        LL x, k, tmp;
        cin >> x >> k;
        LL p, q;
        bool flag = 0;
        for(p = 0; ; p++){
            if(flag){
                break;
            }
            for(q = 0; ; q++){
                if(flag){
                    break;
                }
                LL tmp = p * LL(floor(double(x) / double(k))) + q * LL(ceil(double(x) / double(k)));
                if(tmp > x){
                    break;
                }
                else if(tmp == x){
                    flag = 1;
                }
            }
        }
         cout << p - 1 << " " << q - 1 << '\n';
    }
    return 0;
}
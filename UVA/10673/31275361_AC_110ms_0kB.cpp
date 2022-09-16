#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    while(n--){
        LL x, k, tmp;
        cin >> x >> k;
        if(x % k == 0){
            printf("1 %d\n", k-1);
            continue;
        }
        LL p, q;
        bool flag = 0;
        LL a = LL(floor(double(x) / double(k))), b = LL(ceil(double(x) / double(k)));
        for(p = 0; ; p++){
            for(q = 0; ; q++){
                tmp = p * a + q * b;
                if(tmp > x)
                    break;
                else if(tmp == x)
                    flag = 1;
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        cout << p<< " "<< q<< '\n';
    }
    return 0;
}
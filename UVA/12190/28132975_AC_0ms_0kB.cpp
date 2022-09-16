#include<bits/stdc++.h>
using namespace std;
int range[5] = {0, 200, 29900, 4979900};
int cwh(int price){
    if(price > range[0] && price <= range[1])
        return price / 2;
    else if(price > range[1] && price <= range[2])
        return ((price-200) / 3) + 100;
    else if(price > range[2] && price <= range[3])
        return (price-29900) / 5 + 10000;
    else
        return (price-4979900) / 7 + 1000000;

}
int price_count(int degree){
    if(degree > 0 && degree <= 100)
        return degree * 2;
    else if(degree > 100 && degree <= 10000)
        return (degree-100) * 3 + 200;
    else if(degree > 10000 && degree <= 1000000)
        return (degree-10000) * 5 + 29900;
    else
        return (degree-1000000) * 7 + 4979900;
}
int main(){
    int total, dis, d;
    while(cin>> total>> dis && total!= 0 && dis!=0){
        d = cwh(total);
        int l = 0,r = d;
        int ans;
        while(l<=r){
            int m = (l+r)/2;
            int me = price_count(m), nei = price_count(d - m);
            if(nei - me < dis)
                r = m;
            else if(nei - me > dis)
                l = m+1;
            else{
                ans = me;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

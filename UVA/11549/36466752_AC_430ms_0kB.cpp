#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        long long k;
        cin>> n>> k;
        long long flag = 1;
        while(n--)
            flag *= 10;
        set<int> s;
        while(!s.count(k)){
            s.insert(k);
            k = k * k;
            while(k >= flag)
                k = k / 10;
        }
        cout<< *(s.rbegin())<< endl;
    }

    return 0;
}

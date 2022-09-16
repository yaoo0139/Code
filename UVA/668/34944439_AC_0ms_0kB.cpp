#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    int l = 0;
    while(t--){
        if(l)
            puts("");
        l = 1;
        int n;
        cin>> n;
        vector<int> v;
        int counter = 2;
        while(counter <= n){
            v.emplace_back(counter);
            n -= counter;
            counter++;
        }
        while(n){
            for(int i = v.size()-1; n > 0 && i >= 0; i--, n--)
                v[i]++;
        }
        cout<< v[0];
        for(int i=1; i<v.size(); i++)
            cout<< " "<< v[i];
        cout<< endl;
    }
    return 0;
}
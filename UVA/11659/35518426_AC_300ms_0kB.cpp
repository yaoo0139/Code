#include<bits/stdc++.h>
using namespace std;
vector<int> v[25];
int main(){
    int n, k;
    while(cin>> n>> k){
        if(!n && !k)
            break;
        for(int i=1; i<=n; i++)
            v[i].clear();
        while(k--){
            int a, b;
            cin>> a>> b;
            v[a].emplace_back(b);
        }
        int ans = 0;
        for(int i = 1; i < 1 << n; i++){
            bool flag = true;
            int stat[25] = {0};
            int sum = 0;
            for(int j = 1,bit = 1; j <= n; bit <<= 1, j++){
                if(i & bit){
                    sum ++;
                    stat[j] = 1;
                }
            }

            for(int j=1; j<=n; j++){
                if(stat[j]){
                    for(int u : v[j]){
                        if(u > 0 && !stat[u]){
                            flag = false;
                            break;
                        }
                        else if(u < 0 && stat[-u]){
                            flag = false;
                            break;
                        }
                    }
                }
                if(!flag)
                    break;
            }
            if(flag)
                ans = max(ans, sum);
        }
        cout<< ans<< endl;
    }
    return 0;
}
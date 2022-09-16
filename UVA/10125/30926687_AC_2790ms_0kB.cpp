#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    set<int> s;
    vector<int> v;
    while(cin>> n && n){
        bool flag = false;
        s.clear();
        v.clear();
        while(n--){
            int x;
            cin>> x;
            s.insert(x);
            v.push_back(x);
        }
        int ans = -1e9;
        for(int i=0; i < v.size(); i++){
            for(int j=i+1; j < v.size(); j++){
                for (int k=j+1; k < v.size(); k++){
                    int d = v[i] + v[j] + v[k];
                    if(s.count(d) && d != v[i] && d != v[j] && d != v[k]){
                        flag = true;
                        ans = max(ans, d);
                    }
                }
            }
        }
        if(!flag)
            puts("no solution");
        else
            cout<<ans<<endl;
    }
    return 0;
}
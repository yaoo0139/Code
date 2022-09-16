#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while(cin>> n && n){
        vector<int> v;
        while(n--){
            int x;
            cin>> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        bool flag = false;
        for(int d = v.size()-1; d >= 0; d--){
            for(int a = 0; a < v.size(); a++){
                if(a == d)
                    continue;
                for(int b = a+1; b < v.size(); b++){
                    if(b == d)
                        continue;
                    for(int c = b+1; c < v.size(); c++){
                        if(c == d)
                            continue;
                        if(v[d] == v[a] + v[b] + v[c]){
                            cout<<v[d]<<endl;
                            flag = true;
                            break;
                        }
                    }
                    if(flag)
                        break;
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(!flag)
            puts("no solution");
    }
    return 0;
}
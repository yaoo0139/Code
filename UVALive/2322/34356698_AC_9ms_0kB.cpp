#include<bits/stdc++.h>
using namespace std;
struct wood
{
    int l;
    int w;
    bool operator<(const wood &rhs) const{
        if(l == rhs.l)
            return w < rhs.w;
        return l < rhs.l;
    }
};
bool used[5005];
int main(){
    int t;
    cin>> t;
    while(t--){
        vector<wood> v;
        memset(used, 0, sizeof(used));
        int n;
        cin>> n;
        while(n--){
            int l, w;
            cin>> l>> w;
            v.emplace_back(wood{l, w});
        }
        sort(v.begin(), v.end());
        int counter = 0;
        int ans = 0;
        while(counter != v.size()){
            ans ++;
            wood hold = wood{-1, -1};
            for(int i=0; i<v.size(); i++){
                if(!used[i] && v[i].l >= hold.l && v[i].w >=hold.w){
                    used[i] = true;
                    hold = v[i];
                    counter++;
                }
            }
        }
        cout<< ans<<endl;
    }
}
/*
3
5
4 9 5 2 2 1 3 5 1 4
3
2 2 1 1 2 2
3
1 3 2 2 3 1
*/

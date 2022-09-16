#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> id;
    int a[1000005];
    int x, y;
    cin>> x;
    while(x--){
        id.clear();
        int l = 0, r = 0, len = 0;
        cin>> y;
        for(int i=0;i<y;i++)
            cin>> a[i];
        while(r < y){
            while(r < y && !id.count(a[r])){
                id.insert(a[r]);
                r++;
            }
            len = max(len,(r - l));
            id.erase(a[l]);
            l++;
        }
        cout<< len<< endl;
    }
    return 0;
}

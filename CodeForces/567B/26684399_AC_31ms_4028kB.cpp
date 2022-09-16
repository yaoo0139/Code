#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> room;
    int n;
    int x;
    char c;
    while(cin>> n){
        int ma = 0;
        int pp = 0;
        room.clear();
        for(int i = 0;i < n ;i++){
            cin>> c>> x;
            if(c == '+'){
                pp++;
                room.insert(x);
                ma = max(ma , pp);
            }
            else{
                if(!room.count(x))
                    ma++;
                else{
                    room.erase(x);
                    pp--;
                }
                ma = max(ma , pp);

            }
        }
        cout<< ma<<endl;
    }
    return 0;
}

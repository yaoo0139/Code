#include<bits/stdc++.h>
using namespace std;
map<string, string> fa;
int main(){
    set<string> s, app;
    string a, b;
    int counter = 0;
    while(cin>> a>> b && (a[0] != '-' || b[0] != '-')){
        s.clear();
        fa.clear();
        counter ++;
        bool flag = true;
        fa[b] = a;
        s.insert(a);
        s.insert(b);
        if(a[0] != '0' || b[0] != '0'){
            while(cin>> a>> b && (a[0] != '0' || b[0] != '0')){
                if(fa.count(b))
                    flag = false;
                if(flag){
                    s.insert(a);
                    s.insert(b);
                    fa[b] = a;
                }
            }
        }
        else{
            printf("Case %d is a tree.\n",counter);
            continue;
        }
        string hold;
        if(flag){
            for(auto i = s.begin(); i!=s.end() && flag;i++){
                string x = *i;
                app.clear();
                while(fa.count(x)){
                    if(app.count(x)){
                        flag = 0;
                        break;
                    }
                    app.insert(x);
                    x = fa[x];
                }
                if(i == s.begin() ){
                    hold = x;
                }
                else if(hold != x)
                    flag = false;
            }
            if(flag)
                printf("Case %d is a tree.\n",counter);
            else
                printf("Case %d is not a tree.\n",counter);
        }
        else
            printf("Case %d is not a tree.\n",counter);
    }
    return 0;
}

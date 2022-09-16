#include <bits/stdc++.h>
using namespace std;
string s;
void dfs(int l,int r){
    int x = r;
    while(x >= l && s[x] != '[' && s[x] != ']')
            x--;
    if(s[x] == ']')
        dfs(l, x-1);
    for(int i=x+1;i<=r;i++)
        printf("%c",s[i]);
    if(s[x] == '[')
        dfs(l, x-1);

}
int main(){
    while(cin>> s){
        int l = s.length();
        dfs(0, l-1);
        cout<<endl;
    }
}

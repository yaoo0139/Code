#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int next[2];
    ll v;
    ll len;
};
node tree[500050];
int sz;
ll ans;
void add(string str){
    int now=0;

    for(int i=0;i<str.size();i++){
        int hold = str[i]-'0';
        int next=tree[now].next[hold];
        if(next==-1){
            next= ++sz ;
            tree[next].v = 0;
            tree[next].len = 0;
            memset(tree[next].next, -1, sizeof(tree[next].next));
            tree[now].next[hold] = next;
            tree[next].len = tree[now].len + 1;
        }
        now = next;
        tree[now].v++;
        ans=max(ans,(tree[now].v * tree[now].len));
    }
}
int main(){
    int T;
    cin>> T;
    while(T--){
        ans = 0;
        sz = 0;
        int n;
        string str;
        cin>> n;
        tree[0].v = 0;
        tree[0].len = 0;
        memset(tree[0].next, -1, sizeof(tree[0].next));
        while(n--){
            cin>> str;
            add(str);
        }
        cout<< ans<< endl;
    }
    return 0;
}
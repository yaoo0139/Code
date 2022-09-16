#include<bits/stdc++.h>
using namespace std;
int sz;
struct node
{
    int next[30], val;   
};
node tree[305000];
int dp[305000];
int mod = 20071027;
string str, word;

void insert(string str){
    int u = 0;
    for(int i=0; i<str.size();i++){
        int v = str[i] - 'a';
        if(tree[u].next[v])
            u = tree[u].next[v];
        else{
            tree[u].next[v] = sz++;
            u = tree[u].next[v];
            memset(tree[u].next, 0, sizeof(tree[u].next));
            tree[u].val = 0;
        }
    }
    tree[u].val = 1;
}

void find(int i){
    int u = 0;
    for(int j=i;str[j];j++){
        int v = str[j] - 'a';
        if(!tree[u].next[v])
            return;
        u = tree[u].next[v];
        if(tree[u].val)
            dp[i] = (dp[i] + dp[j+1]) % mod;
    }
}

int main() {
    int n ;
    int cas = 1;
    while(cin>> str){
        memset(tree[0].next, 0, sizeof(tree[0].next));
        memset(dp, 0, sizeof(dp));
        tree[0].val = 0;
        sz = 1;
        cin>> n;
        while(n--){
            cin>> word;
            insert(word);
        }
        dp[str.size()] = 1;
        for(int i=str.size()-1;i>=0;i--)
            find(i);
         printf("Case %d: %d\n", cas++, dp[0]);
    }
    return 0;
}

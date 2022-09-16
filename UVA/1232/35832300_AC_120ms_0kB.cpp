#include<bits/stdc++.h>
using namespace std;
int tree[100005 << 2];
int flag[100005 << 2];
int ans;
void build(int l, int r, int p){
    if(l == r){
        flag[p] = -1;
        tree[p] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, p * 2);
    build(mid+1, r, p * 2 + 1);
    tree[p] = min(tree[p*2+1], tree[p*2]);
}
void update(int ql, int qr, int h, int l, int r, int p){
    if( tree[p] > h )
        return;
    if(ql <= l && r <= qr){
        if( h >= flag[p] && flag[p] != -2){
            ans += r - l + 1;
            flag[p] = tree[p] = h;
            return;
        }
    }

    if(flag[p] >= 0){
        flag[p*2] = flag[p*2+1] = flag[p];
        tree[p*2] = tree[p*2+1] = tree[p];
        flag[p] = -2;
    }

    int m = (l + r) >> 1;
    if(ql <= m)
        update(ql, qr, h, l, m, p*2);
    if(m < qr)
        update(ql, qr, h, m+1, r, p*2+1);

    tree[p] = min(tree[2*p], tree[2*p+1]);
}
int main(){
    int t;
    cin>> t;
    while(t--){
        build(1, 100005, 1);
        flag[1] = 0;
        ans = 0;
        int n;
        cin>> n;
        while(n--){
            int l, r, h;
            cin>> l>> r>> h;
            update(l, r-1, h, 1, 100005, 1);
        }
        cout<< ans<< endl;
    }

    return 0;
}
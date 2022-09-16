#include<bits/stdc++.h>
using namespace std;
struct node{
    int idx;
    int x;
    int y;
};
struct edge{
    int u;
    int v;
    int w;
    bool operator<(const edge &rhs) const{
        return w < rhs.w;
    }
};
int n;
int ans;
node city[100005];
vector<edge> G;
int fa[100005];
int findroo(int x){
    if(fa[x] == x)
        return x;
    return fa[x] = findroo(fa[x]);
}
bool cmp(node a, node b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(node a, node b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}
void kruskal(){
    int line = 0;
    for(int i=0; i<G.size(); i++){
        int a = findroo(G[i].u);
        int b = findroo(G[i].v);
        if(a == b)
            continue;
        fa[a] = b;
        ans += G[i].w;
        line ++;
        // cout<< ans<< endl;
        if(line == n)
            break;
    }
}
int main(){

    while(cin>> n){
        ans = 0;
        G.clear();
        for(int i=0; i<n;i++){
            fa[i] = i;
            city[i].idx = i;
            cin>> city[i].x>> city[i].y;
        }
        sort( city, city + n, cmp);
        for(int i=0; i<n-1; i++)
            G.emplace_back(edge{city[i].idx, city[i+1].idx, min( abs(city[i].x - city[i+1].x), abs(city[i].y - city[i+1].y))});
        sort( city, city + n, cmp2);
        for(int i=0; i<n-1; i++)
            G.emplace_back(edge{city[i].idx, city[i+1].idx, min( abs(city[i].x - city[i+1].x), abs(city[i].y - city[i+1].y))});
        sort(G.begin(), G.end());
        // for(auto i : G)
        //     cout<< i.u<<"->"<<i.v<<":"<< i.w<<endl;
        kruskal();
        cout<< ans<< endl;
    }
}
/*
3
1 5
3 9
7 8
6
8 3
4 9
12 19
18 1
13 5
7 6
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int c, s, q;
    int cas = 0;
    while(cin>> c>> s>> q){
        if(!c && !s && !q)
            break;
        if(cas)
            puts("");
        printf("Case #%d\n", ++cas);
        int dis[105][105] = {0};
        for(int i=1; i<=c; i++){
            for(int j=1; j<=c; j++){
                dis[i][j] = 1e9;
            }
        }
        while(s--){
            int a, b, db;
            cin>> a>> b>> db;
            dis[a][b] = dis[b][a] = db;
        }
        for(int k=1; k<=c; k++){
            for(int i=1; i<=c; i++){
                if(i == k)
                    continue;
                for(int j=i+1; j<=c; j++){
                    dis[j][i] = dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
                }
            }
        }
        while(q--){
            int a, b;
            cin>> a>> b;
            if(dis[a][b] == 1e9)
                puts("no path");
            else
                cout<< dis[a][b]<< endl;
        }
    }
    return 0;
}

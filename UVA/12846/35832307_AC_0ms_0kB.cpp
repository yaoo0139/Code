//20220413
#include <bits/stdc++.h>
using namespace std;
int SG[25] = {0, 1, 2};
bool used[25];
void build(){
    for (int i = 3; i < 20; ++i){
        memset(used, 0, sizeof(used));
        for( int j = 0; j <= i/2; j++){
            used[SG[j]^SG[i-j-1]] = true;
            used[SG[j]^SG[i-j-2]] = true;
        }
        for (int j = 0; j <= 20; ++j){
            if(!used[j]){
                SG[i] = j;
                break;
            }
        }
    }
}
int main(){
    build();
    int cas;
    cin>> cas;
    for (int counter = 1; counter<=cas; counter++){
        int n, k;
        cin>> n>> k;
        memset(used, 0, sizeof(used));
        while(k--){
            int x;
            cin>> x;
            used[x] = true;
        }
        int s = 1;
        while(!used[s])
            s++;
        int a;
        bool flag = false;
        int c = 0;
        int i = s+1;
        if(i >= n)
            i%=n;
        for(; i!=s;i++,c++){
            if(used[i]){
                if(!flag){
                    a = SG[c];
                    flag = 1;
                }
                else
                    a ^= SG[c];
                c = -1;
            }
            if(i == n)
                i = 0;

        }
        if(flag == 0)
            a = SG[c];
        else
            a ^= SG[c];
        printf("Case %d: ", counter);
        if(a)
            puts("yes");
        else
            puts("no");
    
    } 
}
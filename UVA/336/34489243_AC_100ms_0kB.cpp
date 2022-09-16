#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main(){
    int n;
    int cas = 0;
    while(cin>> n && n){
        for(int i=0; i<n*2; i++){
            for(int j=0; j<n*2; j++){
                dp[i][j] = 1e5;
            }
        }
        map<string, int> mp;
        int counter = 0;
        for(int i=0; i<n; i++){
            string str1, str2;
            cin>> str1>> str2;
            if(!mp.count(str1))
                mp[str1] = counter++;
            if(!mp.count(str2))
                mp[str2] = counter++;
            dp[mp[str1]][mp[str2]] = dp[mp[str2]][mp[str1]] = 1;
        }
        for(int i=0;i<counter;i++)
            dp[i][i] = 0;
        for(int i=0; i<counter; i++){
            for(int j=0; j<counter; j++){
                for(int k=0; k<counter; k++){
                    dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
                }
            }
        }
        string str;
        long long q;
        while(cin>> str>> q){
            if(str == "0" && q == 0)
                break;
            int ans = 0;

            if(!mp.count(str))
                ans = counter;
            else{
                for(int i=0; i<counter; i++){
                    if(dp[mp[str]][i] > q)
                        ans++;
                }
            }
            printf("Case %d: %d nodes not reachable from node ",++cas, ans);
            cout<< str<<" with TTL = "<<q<<".\n";
        }
    }
    return 0;
}
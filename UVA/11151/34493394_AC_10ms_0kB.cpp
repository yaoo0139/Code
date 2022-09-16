#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string str;
int main(){
    int n;
    cin>> n;
    getline(cin, str);
    while(n--){
        getline(cin, str);
        if(str.size() == 0){
            cout<<"0\n";
            continue;
        }
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<str.size(); i++){
            dp[i][i] = 1;
            if(i){
                if(str[i] == str[i-1])
                    dp[i-1][i] = 2;
                else
                    dp[i-1][i] = 1;
            }
        }

        for(int l=2; l<str.size();l++){
            for(int i=0; i<str.size()-l; i++){
                if(str[i] == str[i + l])
                    dp[i][i+l] = dp[i+1][i+l-1] + 2;
                else
                    dp[i][i+l] = max(dp[i+1][i+l], dp[i][i+l-1]);
            }
        }
        
        cout<<dp[0][str.size()-1]<< endl;
    }
    return 0;
}
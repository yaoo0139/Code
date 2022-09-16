#include <bits/stdc++.h>
using namespace std;
bool posi(int c){
    return c >= 0 && c <= 9;
}
string sub(string a, string b){
    string hold;
    int pb = b.size() -1;
    hold.clear();
    for(int i = a.size()-1; i >= 0; i--, pb--){
        if(i >= a.size()-b.size()){
            if(posi(a[i] - b[pb]))
                hold.push_back(a[i] - b[pb] + '0');
            else{
                a[i-1]--;
                hold.push_back(a[i] - b[pb] + '0' + 10);
            }
        }
        else{
            if(posi(a[i]- '0' ))
                hold.push_back(a[i]);
            else{
                a[i-1]--;
                hold.push_back(a[i] + 10);
            }
        }
    }
    reverse(hold.begin(),hold.end());
    if(hold[0] == '0'){
        int i;
        string hold2;
        hold2.clear();
        for(i=0;hold[i]=='0';i++){}
        for(;i<hold.size();i++)
            hold2.push_back(hold[i]);
        hold = hold2;
    }
    return hold;
}
string mul(string a){
    string hold;
    hold.clear();
    int carry = 0;
    for(int i = a.size()-1; i >= 0; i--){
        int x = (a[i] - '0') * 3 + carry;
        carry = x / 10;
        x = x % 10;
        hold.push_back(x + '0');
    }
    if(carry != 0)
         hold.push_back(carry + '0');
    reverse(hold.begin(),hold.end());
    return hold;
}
int main()
{
    map<string, string> dp;
    dp["1"] = "1";
    dp["2"] = "3";
    dp["3"] = "8";
    string num;
    for(int i = 4;i <= 2000; i++){
        string a = to_string(i);
        dp[a] = sub(mul(dp[sub(a, "1")]), dp[sub(a, "2")]);
    }
    while(cin>>num && num != "0")
    {
        cout<<dp[num]<<endl;
    }
    return 0;
}

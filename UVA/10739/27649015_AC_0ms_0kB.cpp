#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int t;
    int l;
    cin>> t;
    int counter = 0;
    while(t--)
    {
        counter ++;
        short dp[1005][1005]={0};
        cin >> str;
        l = str.length();
        for(int x = 1; x < l; x++)
        {
            for(int i = 0, j = i + x; j < l ; i++,j++)
            {
                if(str[i] == str[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min(min(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1])+1;

            }
        }
        cout<<"Case "<<counter<<": "<<dp[0][l-1]<<endl;
    }

    return 0;
}

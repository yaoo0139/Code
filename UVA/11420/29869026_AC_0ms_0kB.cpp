#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long dp[70][70][2] = {0};
	dp[1][0][0] = dp[1][1][1] = 1;
	for(int i=2;i<=65;i++){
		dp[i][0][0] = dp[i-1][1][1] + dp[i-1][0][0];
		for(int j=1;j<=i;j++){
			dp[i][j][0] = dp[i-1][j+1][1] + dp[i-1][j][0];
			dp[i][j][1] = dp[i-1][j-1][1] + dp[i-1][j-1][0];
		}
	}
	int a, b;
	while(cin>> a>> b){
		if(a<0&&b<0)
			break;
		cout<<dp[a][b][0] + dp[a][b][1]<<endl;
	}
	return 0;
}
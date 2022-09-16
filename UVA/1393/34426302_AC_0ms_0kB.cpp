#include<bits/stdc++.h>
using namespace std;
long long dp[350][350];
long long ans[350][350];
int main(){
	int n, m;
	for(int i=1; i<305; i++){
		for(int j=1; j<305; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			if(__gcd(i, j) == 1)
				dp[i][j] ++;
			ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1] + dp[i][j] - dp[i/2][j/2]; 
		}
	}
	while(cin>> n>> m){
		if(!n && !m)
			break;
		cout<< (long long)ans[n-1][m-1] * 2<< endl;
	}
	return 0;
}
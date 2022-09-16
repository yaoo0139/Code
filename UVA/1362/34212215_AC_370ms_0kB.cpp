#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000000;
ll dp[305][305];
string str;
ll solve(int i, int j){
	if(i == j)
		return dp[i][j] = 1;
	else if(str[i] != str[j])
		return dp[i][j] = 0;
	else if((j - i) % 2)
		return dp[i][j] = 0;
	ll ans = dp[i][j];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int k=i+2; k<=j;k++)
		ans = (ans + ((solve(i+1, k-1) % mod) * (solve(k, j) % mod ))% mod) % mod;
	return dp[i][j] = ans;
}
int main(){

	while(cin>> str){
		memset(dp ,-1, sizeof(dp));
		cout<< solve(0, str.size()-1)<<endl;
	}
	return 0;
}

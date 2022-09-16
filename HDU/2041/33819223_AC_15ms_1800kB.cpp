#include<iostream>
using namespace std;
int main(){
	int dp[45] = {0};
	dp[1] = 1;
	for(int i=2; i<=40;i++)
		dp[i] = dp[i-1] + dp[i-2];
	int T;
	cin>> T;
	int N;
	while(T--){
		cin>> N;
		cout<< dp[N]<< endl;
	}
	return 0;
}
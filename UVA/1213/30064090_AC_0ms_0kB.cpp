#include<bits/stdc++.h>
using namespace std;
bool prime[1200];
vector<int> p;
int dp[1200][20];
void build(){
	for(int i=2;i<=1120;i++){
		if(!prime[i]){
			p.push_back(i);
			for(int j=i+i;j<=1120;j+=i)
				prime[j] = true;
		}
	}


	dp[0][0] = 1;
	for (int k = 0; k < p.size(); ++ k) {
		for (int i = 1120; i >= p[k]; -- i) {
			for (int j = 1; j <= 14; ++ j) {
				dp[i][j] += dp[i-p[k]][j-1];
			}
		}
	}
}

int main(){
	int a, b;
	build();
	while(cin>> a>> b){
		if(!a && !b)
			break;
		cout<<dp[a][b]<<endl;
	}
	return 0;
}
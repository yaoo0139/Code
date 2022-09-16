//20220309
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int main(){
	int t;
	cin>> t;
	int l=0;
	while(t--){
		if(l)
			puts("");
		l=1;
		int n, m;
		cin>> n>> m;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				dp[i][j] = 0;
		for(int i=1; i<=n; i++){
			int x;
			string str;
			stringstream ss;
			cin>> x;
			getline(cin, str);
			ss<< str;
			int y;
			while(ss >> y){
				dp[x][y] = -1;
			}

		}
		dp[1][1] = 1;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(dp[i][j] == -1)
					continue;
				if(dp[i-1][j] != -1)
					dp[i][j] += dp[i-1][j];
				if(dp[i][j-1] != -1)
					dp[i][j] += dp[i][j-1];
			}
		}
		cout<< dp[n][m]<< endl;
	}

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	long long dp[45], pre[45];
	dp[0] = pre[0] = 0;
	dp[1] = pre[1] = 1;
	for(int i=2; i<40; i++){
		dp[i] = dp[i-1] + dp[i-2];
		pre[i] = pre[i-1] + dp[i];
	}
	cin>> t;
	while(t--){
		bool used[40] = {0};
		int n;
		cin>> n;
		int target;
		for(int i=0; i<39;i++){
			if(pre[i] >= n){
				target = i;
				break;
			}
		}
		used[target] = true;
		int hold = target;
		int ith = n - pre[target-1] - 1;
		while(ith){
			for(int i=0; i<39;i++){
				if(pre[i] >= ith){
					target = i;
					break;
				}
			}
			used[target] = true;
			ith = ith - pre[target-1] - 1;
		}
		for(int i=hold;i>0;i--){
			if(used[i])
				cout<<"1";
			else
				cout<<"0";
		}
		cout<< endl;
	} 

	return 0;
} 

#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,dp[80];
	dp[1]=1;
	dp[2]=dp[3]=2;
	for(i=4;i<=76;i++)
		dp[i]=dp[i-3]+dp[i-2]; 
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",dp[n]);
	}
	
	return 0;
} 
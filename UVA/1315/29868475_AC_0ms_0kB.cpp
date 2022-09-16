#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int arr[35000];
	int sum[35000] = {0};
	for(int i=1,c=0;i<=32767;i=i+2,c++){
		arr[i] = arr[i+1] = c;
	}
	sum[2] = sum[1] = 0;
	for(int i=3;i<=32767;i++){
		sum[i] = arr[i] + sum[i-1];
	}
	int t;
	cin>> t;
	while(t--){
		cin>> n;
		cout<<sum[n]<<endl;
	}
	return 0;
}
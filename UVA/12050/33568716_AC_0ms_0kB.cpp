#include <bits/stdc++.h>
using namespace std;
long long arr[25];
long long pre[25];
int main(){
	for(long long i=1, k=9; i<=19;i++,k=k*10)
		arr[2*i] = arr[2*i-1] = k;
	arr[0] = pre[0] = 0;
	for(long long i=1; i<=19; i++)
		pre[i] = arr[i] + pre[i-1];

	long long n;
	while(cin>> n && n){
		int w;
		for(w = 0; w <= 18; w++){
			if(n <= pre[w])
				break;
		}
		long long dif = n - pre[w-1] - 1;
		
		int digit = (w + 1) / 2;
		int k = 1;
		digit--;
		while(digit--) 
			k*=10;
		string ans;
		ans.push_back(dif / k + 1 + '0');
		dif %= k;
		k /= 10;

		while(k != 0){
			ans.push_back(dif / k + '0');
			dif %= k;
			k /= 10;
		}
		string hold = ans;
		if(w % 2 != 0)
			hold.pop_back();
		reverse(hold.begin(), hold.end());
		ans += hold;
		cout<< ans<< endl;
	}

	return 0;
}
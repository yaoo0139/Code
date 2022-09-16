#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
	return (b==0?a:gcd(b, a%b));
}
ll lcm(ll a, ll b){
	return a * b / gcd(a, b);
}
int main(){
	ll n, m;
	while(cin>> n>> m){
		vector<bool> v;
		ll ans = n;
		int arr[15];
		for(int i=0;i<m;i++)
			cin>> arr[i];
		for(int i=1; i<=m;i++){
			v.clear();
			for(int k=0;k<m-i;k++)
				v.push_back(0);
			for(int k=0;k<i;k++)
				v.push_back(1);
			do{
				ll l = 1;
				for(int k=0;k<v.size();k++){
					if(v[k]){
						l = lcm(l, arr[k]);
					}
				}

				l = n / l;
				if(i%2==1){
					ans = ans - l;
				}
				else{
					ans = ans + l;
				}
			}while(next_permutation(v.begin(), v.end()));
		}
		cout<<ans<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>> n && n){
		int maxx = 0;
		vector<int> v;
		v.push_back(n);
		maxx = max( maxx, abs(n));
		while(cin>> n && n){
			v.push_back(n);
			maxx = max( maxx, abs(n));
		}
		int gcd = abs(v[0] - v[1]);
		for(int j=2;j<v.size();j++)
			gcd = __gcd(gcd, abs(v[j]-v[j-1]));
		
		cout<< gcd<< endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>> t;
	while(t--){
		int n;
		cin>> n;
		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin>> v[i];
		int maxx = v[0];
		int ans = v[0] - v[1];
		for(int i=1; i<n; i++){
			ans = max(ans, maxx - v[i]);
			maxx = max(maxx, v[i]);
		}
		cout<< ans<< endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n;
	while(cin>> n && n){
		bool flag = true;
		int counter = 0;
		int ans = 0;
		vector<int> v;
		for(int i = 0; i < n; i++){
			int x;
			cin>> x;
			v.emplace_back(x);
			ans += x;
			if(x == 0)
				counter++;
		}
		if(ans % 2){
			puts("Not possible");
			continue;
		}
		for(int i=0; i<v.size(); i++){
			sort(v.begin()+i, v.end(), cmp);
			if(v[i] >= n){
				flag = false;
				break;
			}
			for(int j=i+1; j<v.size() && v[i]; j++){
				if(v[j] != 0){
					v[j]--;
					v[i]--;
				}
			}
			if(v[i] > 0){
				flag = false;
				break;
			}
		}
		if(flag)
			puts("Possible");
		else
			puts("Not possible");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool used[25] = {0};
int n, k, m;
bool chk(){
	for(int i=0; i<n; i++){
		if(!used[i]){
			return false;
		}
	}
	return true;
}
int main(){
	
	while(cin>> n>> k>> m){
		if(!n && !k && !m)
			break;
		vector<int> v;
		memset(used, 0, sizeof(used));
		for(int i=1;i<=n; i++)
			v.emplace_back(i);
		int i = v.size()-1;
		int j = 0;
		int counter = 0;
		while(!chk()){
			int t = k % (v.size() - counter);
			if(!t){
				while(used[i]){
					i--;
					i = (i + v.size()) % v.size();
				}	
			}
			// cout<< i<<" "<<j<<endl;
			for(int c = 0; c < t; c++){
				i++;
				i = i % v.size();
				while(used[i]){
					i++;
					i = i % v.size();
				}	
			}
			t = m % (v.size() - counter);
			if(!t){
				while(used[j]){
					j++;
					j = j % v.size();
				}	
			}
			for(int c = 0; c < t; c++){
				j--;
				j = (j + v.size()) % v.size();
				while(used[j]){
					j--;
					j = (j + v.size()) % v.size();
				}	
			}
			//cout<< i<<" "<<j<<endl;
			used[i] = true;
			used[j] = true;
			if(counter)
				printf(",");
			if(i != j){
				counter ++;
				printf("%3d%3d", v[i], v[j]);
			}
			else
				printf("%3d", v[i]);
			counter ++;
			bool flag = true;
			
		}
		cout<< endl;
	}

	return 0;
}
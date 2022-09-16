#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>> n && n){

		while(1){
			
			vector<int> ans(n), v(n);
			for(int i=0; i<n; i++){
				v[i] = i+1;
				cin>> ans[i];
				if(ans[i] == 0)
					break;
			}
			if(ans[0] == 0)
				break;
			stack<int> s;
			int counter = 0;
			for(int i=0; i<n; i++){
				// cout<< counter<< endl;
				while(!s.empty() && ans[counter] == s.top()){
					s.pop();
					counter ++;
				}
				if(ans[counter] == v[i])
					counter ++;
				else
					s.push(v[i]);
			}
			// cout<< counter<< endl;
			while(!s.empty() && s.top() == ans[counter]){
				s.pop();
				counter ++;
			}
			if(counter == v.size())
				puts("Yes");
			else
				puts("No");
		}
		puts("");
	}
	return 0;
}
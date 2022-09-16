#include<bits/stdc++.h>
using namespace std;
int lis[100050];
int num[100050];
int path[100050];
int main(){
	int c, r;
	int counter = 0;
	while(cin >> r>> c){
		bool flag = true;
		vector<int> v;
		if(c == -1 && r == -1)
			break;
		int a, b;
		while(cin>> a>> b){
			if(a == 0 && b == 0)
				break;
			v.push_back( (a-1) * c +  b);
		}
		sort( v.begin(), v.end());
		if(v[v.size()-1] != c * r){
			v.push_back(c * r);
			flag = false;
		}
		
		for(int i = 0; i < v.size(); i++){
			lis[i] = num[i] = 1;
			path[i] = -1;
			for(int j = 0; j < i; j++){
				if( ( v[i] - 1 ) % c >= ( v[j] - 1 ) % c ){
					if( lis[i] < lis[j] + 1){
						lis[i] = lis[j] + 1;
						num[i] = num[j];
						path[i] = j;
					}
					else if(lis[i] == lis[j] + 1)
						num[i] += num[j];
				}
			}
		}

		if(!flag)
			lis[v.size()-1] --;

		printf("CASE#%d: %d %d", ++counter, lis[v.size()-1], num[v.size()-1]);

		vector<int> ans;
		if(flag)
			ans.push_back(v.size()-1); 

		int p = v.size()-1;
		while(p != -1){
			ans.push_back(path[p]);
			p = path[p];
		}

		reverse( ans.begin(), ans.end());
		
		for(int i = 1; i < ans.size(); i++)
			cout<<" "<<v[ ans[i] ];
		cout<< endl;
	}
	return 0;
}
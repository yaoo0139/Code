#include<bits/stdc++.h>
using namespace std;
struct area{
	int s;
	int t;
	bool operator<(const area &rhs) const{
		return t < rhs.t || (t == rhs.t && s > rhs.s);
	}
};
int main(){
	int t, l = 0;
	cin>> t;
	while(t--){
		if(l)
			puts("");
		l = 1;
		bool flag[20005] = {0};
		int ad, p;
		cin>> ad>> p;
		vector<area> v;
		for(int i=0;i<p;i++){
			int a, b;
			cin>> a>> b;
			if(a > b)
				swap(a, b);
			v.push_back(area{a, b});
		}
		vector<int> ans;
		sort(v.begin(), v.end());
		for(auto i : v){

			int counter = 0;
			for(int j = i.s; j <= i.t; j++){
				if(flag[j+10000]){
					counter++;
				}
			}

			for(int j = i.t; j >= i.s && counter < ad; j--){
				if(!flag[j+10000]){
					ans.push_back(j);
					flag[j+10000] = true;
					counter++;
				}
			}
			
		}
		sort(ans.begin(), ans.end());
		cout<< ans.size()<< endl;
		for(int i : ans)
			cout<< i<< endl;
		
	}
}
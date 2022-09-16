#include <bits/stdc++.h>
using namespace std;
struct area{
	int a;
	int b;
	bool operator<(const area rhs) const{
		return a < rhs.a || ( a == a && b < rhs.b);
	}
	bool operator!=(const area rhs) const{
		return a != rhs.a || b != rhs.b;
	}
};
int main(){
	int a, b;
	int counter = 0;
	while(cin>> a>> b){
		counter = 0;
		vector<area> v;
		if(a > b)
			swap(a, b);
		if(a == b)
			counter++;
		v.push_back(area{a, b});
		for(int i=0;i<5;i++){
			cin>> a>> b;
			if(a > b)
				swap(a, b);
			if(a == b)
				counter++;
			v.push_back(area{a, b});
		}
		sort(v.begin(), v.end());
		
		if(counter % 2 != 0 || counter == 4){
			puts("IMPOSSIBLE");
			continue;
		}
		counter /= 2;
		if(counter == 0){
			map<int, int> mp;
			for(int i=0;i<6;i+=2){
				mp[v[i].a]++;
				mp[v[i].b]++;
			}
			if(mp.size() > 3){
				puts("IMPOSSIBLE");
				continue;
			}
			
			for(auto i : mp){
				if(i.second != 2){
					puts("IMPOSSIBLE");
					break;
				}
			}
		}
		else if(counter == 1){
			set<area> s;
			area hold = v[0];
			area temp;
			counter = 0;
			for(int i=0;i<6;i++){
				s.insert(v[i]);
				if(hold != v[i])
					temp = v[i];
			}
			if(s.size() > 2 ||(hold.a != temp.a && hold.b != temp.a && hold.b != temp.a && hold.b != temp.b)){
				puts("IMPOSSIBLE");
				continue;
			}
		}
		else if(counter == 3){
			map<int, int> mp;
			for(int i=0;i<6;i++){
				mp[v[i].a]++;
				mp[v[i].b]++;
			}
			if(mp.size() > 1){
				puts("IMPOSSIBLE");
				continue;
			}
		}
		bool flag = true;
		for(int i=0;i<6;i+=2){
			if(v[i]!=v[i+1]){
				flag = false;
				break;
			}
		}
		if(flag)
			puts("POSSIBLE");
		else
			puts("IMPOSSIBLE");

	}
	return 0;
}
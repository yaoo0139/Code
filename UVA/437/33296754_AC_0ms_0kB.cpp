#include<bits/stdc++.h>
using namespace std;
struct cube{
	int x;
	int y;
	int z;
	bool operator<(cube rhs){
		if(x == rhs.x)
			return y < rhs.y;
		return x < rhs.x;
	}
};
int main(){
	int a[3];
	int n;
	int cas = 0;
	while(cin>> n && n){
		vector<cube> v;
		while(n--){
			cin>> a[0]>> a[1]>> a[2];
			sort(a, a+3);
			do{
				v.push_back({a[0], a[1], a[2]});
			}while(next_permutation(a,a+3));
		}
		sort(v.begin(), v.end());
		int h[200] = {0};
		h[0] = v[0].z;
		for(int i=1;i<v.size();i++){
			h[i] = v[i].z;
		
			int hold = v[i].z;
			for(int j=0;j<i;j++){
				if( v[j].x < v[i].x && v[j].y < v[i].y){
					hold = max(hold, h[j] + v[i].z);
				}
			}
			h[i] = hold;
		}
		int i = *max_element(h, h+v.size());
		printf("Case %d: maximum height = %d\n", ++cas, i);
	}
	return 0;
}

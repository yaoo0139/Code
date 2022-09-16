#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
int trmax[505][2020];
int trmin[505][2020];
int arr[505][505];
int n;
void build(){
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			trmax[k][i+n] = arr[k][i];
			trmin[k][i+n] = arr[k][i];
		}

		for(int i=n-1; i>0; i--){
			trmax[k][i] = max(trmax[k][i<<1], trmax[k][i<<1|1]);
			trmin[k][i] = min(trmin[k][i<<1], trmin[k][i<<1|1]);
		}
	}
}
void update(int k, int id, int val){
	int tmp = id;
	for(trmax[k][id += n] = val; id > 1; id >>= 1){
		trmax[k][id >> 1] = max(trmax[k][id], trmax[k][id ^ 1]);
	}
	id = tmp;
	for(trmin[k][id += n] = val; id > 1; id >>= 1){
		trmin[k][id >> 1] = min(trmin[k][id], trmin[k][id ^ 1]);
	}
}
int  maxquery(int i, int l, int r){
	int ret = -INT_MAX;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l & 1){
			ret = max(ret, trmax[i][l++]);
		}
		if(r & 1){
			ret = max(ret, trmax[i][--r]);
		}
	}
	return ret;
}
int  minquery(int i, int l, int r){
	int ret = INT_MAX;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l & 1){
			ret = min(ret, trmin[i][l++]);
		}
		if(r & 1){
			ret = min(ret, trmin[i][--r]);
		}
	}
	return ret;
}
int main(){
	IOS
	cin>> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>> arr[i][j];
		}
	}
	build();
	int q;
	cin>> q;
	while(q--){
		string cmd;
		cin>> cmd;
		if(cmd == "q"){
			int x1, y1, x2, y2;
			cin>> x1>> y1>> x2>> y2;
			x1--;
			x2--;
			int maxx = -INT_MAX;
			int minn = INT_MAX;
			for(int i = x1; i <= x2; i++)
				maxx = max(maxquery(i, y1 - 1, y2), maxx);
			for(int i = x1; i <= x2; i++)
				minn = min(minquery(i, y1 - 1, y2), minn);
			cout<< maxx<< " "<< minn<< endl;
		}
		else{
			int x, y, val;
			cin>> x>> y>> val;
			update(x-1, y-1, val);
		}
	}
	return 0;
}
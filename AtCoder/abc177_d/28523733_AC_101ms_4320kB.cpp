#include<bits/stdc++.h>
using namespace std;
int fa[200050];
int findroo(int x){
	if(fa[x] < 0)
		return x;
	fa[x] = findroo(fa[x]);
	return fa[x];
}
int main(){
	int n, m;
	while(cin>> n>> m){
		for(int i=1;i<=n;i++)
			fa[i] = -1;
		for(int i=0;i<m;i++){
			int a, b;
			cin>> a>> b;
			a = findroo(a);
			b = findroo(b);
			if(a!=b){
				fa[a] += fa[b];
				fa[b] = a;
			}
		}
		int ma = -1;
		for(int i=1;i<=n;i++)
			ma =min(ma, fa[i]);
		cout<<abs(ma)<<endl;
	}
	return 0;
}
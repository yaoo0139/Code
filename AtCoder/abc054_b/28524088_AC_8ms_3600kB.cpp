#include<bits/stdc++.h>
using namespace std;
int m, n;
char a[70][70];
char b[70][70];
bool check(int x, int y){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(b[j][i] != a[j+x][i+y])
				return false;
	}
	return true;
}
int main(){
	bool flag;
	while(cin>> m>> n){
		flag = false;
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				cin>>a[j][i];
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>b[j][i];
			}
		}

		for(int i=0;i<m-n+1;i++){
			for(int j=0;j<m-n+1;j++){
				if(a[j][i] == b[0][0])
					flag = check(j, i);
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
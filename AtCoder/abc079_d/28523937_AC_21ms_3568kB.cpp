#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main(){
	int x, y;
	while(cin>> y>> x){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				cin>>a[i][j];
			}
		}
		vector<int> t;
		vector<int> hold;
		for(int i=0;i<10;i++)
			t.push_back(a[i][1]);
		do{
			hold = t;
			for(int i=0;i<10;i++){
				for(int k=0;k<10;k++){
					t[i] = min(t[i], a[i][k] + t[k]);
				}
			}
		}while(t!=hold);
		int sum = 0;
		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++){
				int a;
				cin>> a;
				if(a!=-1){
					sum += t[a];
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
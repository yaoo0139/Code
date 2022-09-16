#include<bits/stdc++.h>
using namespace std;
int main(){
	string str[7]= {"abc", "acb", "bac", "bca", "cab", "cba"};
	int n;
	while(cin>> n){
		if(n==1){
			printf("a\nb\nc\n");
			continue;
		}
		int times = n / 3 ;
		int back = 3 - (n % 3) ;
		if(n * 6 >= 100000){
			puts("TOO LONG");
			continue;
		}
		for(int i=0;i<6;i++){
			for(int k=0;k<times;k++)
				cout<<str[i];
			for(int k=0;k<3-back;k++)
				cout<<str[i][k];
			cout<<endl;
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b;
	while(cin>> a>> b){
		if(a==1)
			a=14;
		if(b==1)
			b=14;
		if(a==b)
			puts("Draw");
		else
			cout<<(a>b?"Alice":"Bob")<<endl;
	}
	return 0;
}
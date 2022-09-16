#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
	if(n >= 101)
		return n - 10;
	else
		return factorial(factorial(n + 11));
}
int main(){
	int n;
	while(cin>> n && n)
		cout<< "f91("<< n<<") = "<<factorial(n)<< endl;
	return 0;
}
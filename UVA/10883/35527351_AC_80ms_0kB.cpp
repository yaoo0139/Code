#include<bits/stdc++.h>
using namespace std;
double c;
int n;
double sol(double a){
	return c + log(a) - (n-1) * log(2);
}
int main(){
	int t;
	cin>> t;
	for(int cas = 1; cas <= t; cas++){
		c = 0;
		double sum = 0;
		double a;
		cin>> n;
		for(int i=0; i<n; i++){
			cin>> a;
			if(a < 0)
				sum -= exp(sol(-a));
			else
				sum += exp(sol(a));
			c += log(n - i - 1) - log (i + 1);
		}
		printf("Case #%d: %.3lf\n", cas, sum);
	}
	return 0;
}
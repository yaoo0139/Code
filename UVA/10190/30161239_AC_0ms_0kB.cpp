#include<bits/stdc++.h>
using namespace std;
int main(){
	
	vector<long long> v;
	long long n, m;
	while(cin>> n>> m){
		bool flag = true;
		if( m == 1  || n < m || m <= 0)
			flag = false;
		v.clear();
		while(n >= m && flag){
			if(n % m != 0){
				flag = false;
				break;
			}
			v.push_back(n);
			n=n/m;
		}
		if(flag && n == 1){
			for(long long i : v)
				cout<<i<<" ";
			cout<<"1"<<endl;
		}
		else
			puts("Boring!");
	}

	return 0;
}
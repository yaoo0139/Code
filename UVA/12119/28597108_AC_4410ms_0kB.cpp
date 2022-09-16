#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	return b==0 ? a : gcd(b, a%b);	
}
int main(){
	long long lcm;
	int counter = 1;
	while(~scanf("%lld", &lcm) && lcm != 0 ){
		printf("Scenario %d:\n", counter++);
		bool flag = false;

		for(long long i = 1;i<=lcm && i<=1000000;i++){
			if(lcm % i)
				continue;

			for(long long j = i+1;j <= i+25; j++){
				if(lcm % j)
					continue;

				long long tmp = (i * j) / gcd(i, j);
				for(long long k = j+1;k <= i+25 && k<=1000000; k++){
					if(lcm % k)
						continue;

					long long ans = (tmp *  k ) / gcd(tmp, k);
					if(ans == lcm){
						printf("%lld %lld %lld\n",i,j,k);
						flag = true;
					}
				}
			}
		}
		if(!flag)
			puts("Such bells don't exist");
		printf("\n");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
	return b==0 ? a : gcd(b, a%b);	
}
 
int main() {
	long long lcm;
	int cas = 1;
	while (scanf("%lld", &lcm) != EOF && lcm) {
		printf("Scenario %d:\n", cas++);
		int flag = 0;
		for (long long i = 1; i <= 1000000 && i <= lcm; i++) {
			if (lcm % i)
				continue;
			for (long long j = i+1; j-i <= 25; j++) {
				if (lcm % j)
					continue;
				long long tmp = (i * j) / gcd(i, j);
				for (long long k = j+1; k-i <= 25 && k <= 1000000; k++) {
					if (lcm % k)
						continue;
					long long ans = (tmp * k) / gcd(tmp, k);
					if (ans == lcm) {
						printf("%lld %lld %lld\n", i, j, k);
						flag = 1;
					}
				}
			}
		}
		if (!flag) 
			printf("Such bells don't exist\n");
		printf("\n");
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxn = 1000000;
 
ll gcd(ll a, ll b) {
	return b==0 ? a : gcd(b, a%b);	
}
 
int main() {
	ll lcm;
	int cas = 1;
	while (scanf("%lld", &lcm) != EOF && lcm) {
		printf("Scenario %d:\n", cas++);
		int flag = 0;
		for (ll i = 1; i <= maxn && i <= lcm; i++) {
			if (lcm % i)
				continue;
			for (ll j = i+1; j-i <= 25; j++) {
				if (lcm % j)
					continue;
				ll tmp = (i * j) / gcd(i, j);
				for (ll k = j+1; k-i <= 25 && k <= maxn; k++) {
					if (lcm % k)
						continue;
					ll ans = (tmp * k) / gcd(tmp, k);
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
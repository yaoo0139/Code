#include<stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long a, b = 0, hold;
		int counter = -1;
		scanf("%lld", &a);
		while(a != b || !counter){
			a = a + b;
			hold = a;
			b = 0;
			while(hold != 0){
				b = b * 10 + hold % 10;
				hold /= 10;
			}
			counter++;
		}
		printf("%d %lld\n", counter, a);
	}

	return 0;
}
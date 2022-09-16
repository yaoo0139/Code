#include <cstring>
#include <cstdio>
 
int main()
{
	int n, A, B, C, x, y, z;
	while (~scanf("%d",&n))
	while (n --) {
		scanf("%d%d%d",&A,&B,&C);
		int flag = 0;
		for (x = -100; x+x+x < A; ++ x) {
			if (x*x >= C || x && B%x) continue;
			for (y = x+1; x+y+y < A; ++ y) {
				z = A - x - y; 
				if (y < z && x*y*z == B && x*x+y*y+z*z == C) {
					flag = 1;break;
				}
			}
			if (flag) break;
		}
		if (flag)
			printf("%d %d %d\n",x,y,z);
		else printf("No solution.\n");
	} 
    return 0;
}

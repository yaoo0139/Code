#include <stdio.h>
#include <stdlib.h>
int main (){
	int a,b,i,z;
	scanf("%d",&z);
	for(i=1;i<=z;i++){
		scanf("%d %d",&a,&b);
		if (a>b)
			printf (">\n");
		if (a<b)
			printf ("<\n");
		if (a==b)
			printf ("=\n");
	}
	return 0;
} 
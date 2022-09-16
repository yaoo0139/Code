#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,r;
	while(~scanf("%d %d",&n,&r)){
		printf("%d\n",n>r?n-r:r+n);
	}
	return 0;    
} 
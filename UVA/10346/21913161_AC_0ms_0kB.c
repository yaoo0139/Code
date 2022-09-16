#include <stdio.h>
#include <stdlib.h>
int main (){
	int n,k,l,total=0,x,b;
	
	while(scanf("%d %d",&n,&k)!=EOF){
	l=n;
	total= total+ n;
	
	while (l>=k){
	n=l/k; 
	l=l%k; 
	total +=n; 
	l+=n; 
	}
	printf("%d\n",total); 
	total=0;
} 
	return 0;
} 
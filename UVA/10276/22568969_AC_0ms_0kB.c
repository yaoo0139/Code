#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[60],n,i,c=4,q;
	a[1]=1;
	a[2]=3;
	for(i=3;i<=49;i=i+2){
		a[i]=a[i-1]+c;
		a[i+1]=a[i]+c;
		c=c+2;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&q);
		printf("%d\n",a[q]);
	}			
	return 0;
}
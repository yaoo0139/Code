#include<stdio.h>
#include<stdlib.h>
int cur(int a, int b, int c, int x){
	if(x==1)
		return a;
	if(x==2)
		return b;
	if(x==3)
		return c;
	return cur(b,c,a+b,x-1);
}
int main(){
 	int n;
    while(~scanf("%d",&n))
        printf("%d\n",cur(1,2,2,n));
    return 0;
}
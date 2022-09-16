#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){

    int i,x,y,a[35],c,k;
    while(scanf("%d",&i)!=EOF){
    	if(i==0)
    		break;
    	c=0;
    	for(x=0;i!=0;x++){
    		a[x]=i%2;
    		if(a[x]==1)
    			c++;
    		i=i/2;
		}
		printf("The parity of ");
		for(y=x-1;y>=0;y--)
    		printf("%d",a[y]);
		printf(" is %d (mod 2).\n",c);	
	}
    return 0;
}
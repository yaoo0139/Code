#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    double c;
    int i,n,b,x,aa;
    while(scanf("%d",&n)!=EOF){
    	c=1;
    	x=0;
    	for(i=0;i<n;i++){
    		c=c/2;
    		b=c;
    		if(b==0){
    			c=c*10;
    			x++;
    		}
		}
		printf("2^-%d = %.3lfe-%d\n",n,c,x);
    }
    return 0;
}
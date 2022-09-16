#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    double n,x;
    int t,i;
    long long r;
    while(scanf("%d",&t)!=EOF){
    	for(i=1;i<=t;i++){
    		scanf ("%lf",&n);
    		r=sqrt(2*n+0.25)-0.5;
    		printf("%lld\n",r);
    		
    	}
    }
    return 0;
}
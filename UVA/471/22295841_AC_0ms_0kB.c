#include<stdio.h>
#include<stdlib.h>
int check(long long int x){
	int g[15],i,p=1;
	for(i=0;i<=9;i++)
		g[i]=0;
	while(x!=0){
		g[x%10]++;
		x=x/10;
	}
	for(i=0;i<=9;i++){
		if(g[i]>1){
			p=0;
			return 0;
		}
	}
	if(p)
		return 1;
}
int main(){
    long long int a,i,n,r=0;
    while(scanf("%lld",&n)!=EOF){
	    while(n--){
	    	if(r)
    			printf("\n");
	    	r=1;
    		scanf("%lld",&a);
    		for(i=1;i<=9876543210;i++){
    			if(a*i>9876543210)
    				break;
    			if(check(i)&&check(a*i))
                             printf("%lld / %lld = %lld\n",a*i,i,a);
			}
    	}
	}
    return 0;
}
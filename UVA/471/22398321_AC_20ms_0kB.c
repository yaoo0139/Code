#include<stdio.h>
#include<stdlib.h>
int check(long long int x){
	int i,c,p=1;
	long long int s;
	for(i=0;i<=9;i++){
		c=0;
		s=x;
		while(s!=0){
			if(s%10==i)
				c++;
			s=s/10;
		}
		if(c>1){
			return 0;
			break;
			p=0;
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
    		for(i=1;i<=9876543210/a;i++){
    			if(check(i)&&check(a*i))
                     printf("%lld / %lld = %lld\n",a*i,i,a);
			}
    	}
	}
    return 0;
}
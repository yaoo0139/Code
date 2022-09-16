#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n,i,c;
    while(scanf("%d",&n)!=EOF){
    	c=1;
    	for(i=1;c<n;i++){
    		c=pow(2,i);
    		if(c<=n && pow(2,i+1)>n)
    			printf("%d\n",i+1);
		}
		if(n==1)
			printf("1\n");
    }
    return 0;
}
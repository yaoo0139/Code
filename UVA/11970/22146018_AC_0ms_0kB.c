#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int t,n,i,x,c;
    while(scanf("%d",&t)!=EOF){
        for(i=1;i<=t;i++){
            scanf("%d",&n);
            printf("Case %d:",i);
            for(c=sqrt(n);c*c>=1;c--){
               x=n-c*c;
               if(x/c>0 && x%c==0)
			   	    printf(" %d",x); 
            }
            printf("\n");
        }
    }
    return 0;
}
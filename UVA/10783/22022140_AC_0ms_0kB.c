#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,a,b,i,sum=0,c=0,r;
    while(scanf("%d",&n)!=EOF){
        for(r=1;r<=n;r++){
            c++;
            scanf("%d %d",&a,&b);
            if (a%2==0)
                i=a+1;
            else
                i=a;
            for(;i<=b;i+=2)
                sum+=i;
            printf ("Case %d: %d\n",c,sum);
            sum= 0;
        }
    }

    return 0;
}

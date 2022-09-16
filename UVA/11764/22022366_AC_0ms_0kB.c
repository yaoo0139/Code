#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,t,j,x1=0,x2=0;
    int w,l;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&t);
            for(j=1;j<=t;j++){
                scanf("%d",&w);
                if(j==1)
                    l=w;
                else if (l>w)
                    x1++;
                else if (l<w)
                    x2++;
                l=w;
            }
        printf("Case %d: %d %d\n",i,x2,x1);
        x1=0;
        x2=0;
        }
    }

    return 0;
}

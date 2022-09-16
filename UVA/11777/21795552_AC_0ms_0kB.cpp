#include <stdio.h>
#include <stdlib.h>
int main(){

    int t,n,sum=0,t1,t2,t3,i;
    scanf ("%d", &t);
    for (i=1;i<=t;i++){
        for (int x=1;x<=4;x++){
            scanf ("%d", &n);
            sum= sum+ n;
        }
        scanf("%d %d %d",&t1,&t2,&t3);
        if (t1<=t2 && t1<=t3)
            sum= sum+ (t2+t3)/2;
        else if (t2<=t1 && t2<=t3)
            sum= sum+ (t1+t3)/2;
        else if (t3<=t2 && t3<=t1)
            sum= sum+ (t1+t2)/2;
        if (sum>=90)
            printf ("Case %d: A\n",i);
        else if (90> sum && sum>= 80)
            printf ("Case %d: B\n",i);
        else if (80> sum && sum>= 70)
            printf ("Case %d: C\n",i);
        else if (70> sum && sum>= 60)
            printf ("Case %d: D\n",i);
        else if (sum< 60)
            printf ("Case %d: F\n",i);
        sum= 0;
    }
    return 0;
}

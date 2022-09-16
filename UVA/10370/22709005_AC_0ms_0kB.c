#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[1005],t,n,i,j,sum,av,c;
    float r;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);
        sum=0;
        c=0;
        for(j=1; j<=n; j++)
            scanf("%d",&a[j]);
        for(j=1; j<=n; j++)
            sum+=a[j];
        av=sum/n;
        for(j=1; j<=n; j++)
            if(a[j]>av)
                c++;
        r=(float)c/n;
        printf("%.3f%%\n",(float)c/n*100);
    }
    return 0;
}

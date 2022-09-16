#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[80],i,n;
    a[1]=1;
    a[2]=a[3]=2;
    for(i=4;i<=76;i++)
        a[i]=a[i-3]+a[i-2];
    while(~scanf("%d",&n))
        printf("%d\n",a[n]);
    return 0;
}

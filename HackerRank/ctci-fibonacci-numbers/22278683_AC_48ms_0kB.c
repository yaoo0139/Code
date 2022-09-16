#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[35],n,i;
    a[0]=0;
    a[1]=1;
    while(scanf("%d",&n)!=EOF){
        for(i=2;i<=n;i++){
            a[i]=a[i-2]+a[i-1];
        }
        printf("%d\n",a[n]);
    }


    return 0;
}

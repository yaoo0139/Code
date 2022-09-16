#include<stdio.h>
#include<stdlib.h>
int main(){
    long long int a[35],n,i;
    a[0]=0;
    a[1]=1;
    while(scanf("%lld",&n)!=EOF){
        for(i=2;i<=n;i++){
            a[i]=a[i-2]+a[i-1];
        }
        printf("%lld\n",a[n]);
    }


    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[60],t,i,n,c=4;
    a[1]=1;
    a[2]=3;
    for(i=3;i<=50;i=i+2){
        a[i]=a[i-1]+c;
        a[i+1]=a[i]+c;
        c=c+2;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}

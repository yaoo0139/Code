#include<stdio.h>
#include<stdlib.h>
int factorial(int r,int n){
    int i;
    r=1;
    for(i=2;i<=n;i++){
        r=r*i;
    }
    return r;
}

int main(){
    int n,i,x;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",factorial(1,n));
    }
    return 0;
}

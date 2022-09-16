#include <stdio.h>
#include <stdlib.h>
int main(){

    int t,n,i;
    scanf ("%d", &t);
    for (i=1;i<=t;i++){
        scanf ("%d", &n);
        n=n*567/9+7492;
        n=n*235/47-498;
        if (n>=0)
            printf("%d\n",n%100/10);
        else{
            n=-n;
            printf("%d\n",n%100/10);
        }
    }
    return 0;
}

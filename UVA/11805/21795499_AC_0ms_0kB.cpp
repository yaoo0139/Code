#include <stdio.h>
#include <stdlib.h>
int main(){

    int t,n,k,p,ans;
    scanf ("%d", &t);
    for (int i=1;i<=t;i++){
        scanf ("%d %d %d",&n,&k,&p);
        if((k+p)%n==0)
            ans= n;
        else
            ans= (k+p)%n;
        printf ("Case %d: %d\n",i,ans);
    }
    return 0;
}

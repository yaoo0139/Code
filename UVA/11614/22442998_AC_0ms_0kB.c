#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    double n;
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf ("%lf",&n);
        printf("%.0lf\n",floor(sqrt(2*n+0.25)-0.5));
    }
    return 0;
}

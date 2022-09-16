#include<stdio.h>
#include<stdlib.h>
int main(){
    int t, i, a, b, c, d, e, f, g, x, sum;
        scanf ("%d", &t);
    for (i=1;i<=t;i=i+1 ){
        sum=0;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
        sum=a+b+c+d;
        if( e<=f && e<=g)
            x=(f+g)/2;
        else if( f<=e && f<=g)
            x=(e+g)/2;
        else if( g<=e && g<=f)
            x=(e+f)/2;
        sum=sum+x;
        if(sum>=90)
            printf("Case %d: A\n", i);
        if(sum<90 && sum>=80)
            printf("Case %d: B\n", i);
        if(sum<80 && sum>=70)
            printf("Case %d: C\n", i);
        if(sum<70 && sum>=60)
            printf("Case %d: D\n", i);
        if(sum<60)
            printf("Case %d: F\n", i);
    }
    return 0;
}

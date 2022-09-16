#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,b,c,r,x;
    scanf("%d %d",&a,&b);
    while(a!= 0 || b!=0){
        c=0;
        r=0;
        while(a!=0 || b!=0){
            if(a%10+b%10+r>=10){
                c++;
                r=(a%10+b%10+r)/10;
                a/=10;
                b/=10;
            }
            else{
                a/=10;
                b/=10;
                r=0;
            }
        }
        if (c>1)
            printf ("%d carry operations.\n",c);
        else if(c==1)
            printf ("%d carry operation.\n",c);
        else
            printf ("No carry operation.\n",c);
        scanf("%d %d",&a,&b);
    }
    return 0;
}

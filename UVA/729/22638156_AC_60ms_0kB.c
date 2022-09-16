#include<stdio.h>
#include<stdlib.h>
int times(long long n,long long h){
    long long a=1,b=1,c=1,i;
    for(i=1;i<=n;i++)
        a*=i;
    for(i=1;i<=h;i++)
        b*=i;
    for(i=1;i<=n-h;i++)
        c*=i;
    return a/(b*c);
}
int main(){
    int t,i,p,t2,l=0;
    long long n,h,c;
    char a[30];
    scanf("%d",&t);
    while(t--){
        if(l)
            printf("\n");
        p=1;
        scanf("%lld %lld",&n,&h);
        a[n]='\0';
        c=times(n,h);
        for(i=n-1;i>=0;i--)
            a[i]='0';
        for(i=n-1;i>=n-h;i--)
            a[i]='1';
        puts(a);
        while(p!=c){
            t2=0;
            a[n-1]++;
            for(i=n-1;i>0;i--){
                if(a[i]=='2'){
                    a[i]='0';
                    a[i-1]++;
                }
            }
            for(i=n-1;i>=0;i--)
                if(a[i]=='1')
                    t2++;
            if(t2==h){
                puts(a);
                p++;
            }
        }
        l=1;
	}
	return 0;    
} 
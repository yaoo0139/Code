#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[15],n,i,x1,x2,r,c,j,p,l=1;
    scanf("%d",&n);
    while(n!=0){
        if(l==0)
            printf("\n");
        p=0;
        l=0;
        for(i=1000;i<100000/n;i++){
            r=1;
            x1=i;
            x2=i*n;
            c=5;
            for(j=0;j<=9;j++)
                a[j]=0;
            while(c--){
                a[x1%10]++;
                x1/=10;
            }
            c=5;
            while(c--){
                a[x2%10]++;
                x2/=10;
            }
            for(j=0;j<=9;j++){
                if(a[j]>1)
                    r=0;
            }
            x1=i;
            x2=i*n;
            if(r==1){
                p=1;
                if(i<10000)
                    printf("%d / 0%d = %d\n",x2,x1,n);
                else
                    printf("%d / %d = %d\n",x2,x1,n);
            }
        }
        if (p==0)
            printf("There are no solutions for %d.\n",n);
        scanf("%d",&n);
    }


    return 0;
}

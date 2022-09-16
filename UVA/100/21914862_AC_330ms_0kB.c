#include <stdio.h>
#include <stdlib.h>
int main (){
	int n=1,i,j,max=0,x,l,r,a,b;
	while(scanf("%d %d",&i,&j)!=EOF){
        if (i > j){
            a = i;
            b = j;
            r = j;
            j = i;
            i = r;
        }
        else {
            a= i;
            b= j;
        }
		for (l=i;l<=j;l++){
			x=l;
			while(x!=1){
				n++;
				if (x%2==0)
					x=x/2;
				else
					x=x*3+1;
			}
			if (n>max)
				max=n;
			n=1;
		}
        printf ("%d %d %d\n",a,b,max);
		max=0;
	}
	return 0;
}

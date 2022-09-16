#include<stdio.h>
#include<stdlib.h>
int main(){
    int z,i,m,l,a[50000],x,p=0,c=0,r,q;
    scanf("%d %d %d %d",&z,&i,&m,&l);
    while(z!=0 && i!=0 && m!=0 && l!=0){
    	p++;
    	c=0;
    	r=l;
    	q=0;
        for(x=0;x<=50000;x++)
            a[x]=0; 
        while(a[l]==0){
        	c++;
        	a[l]++;
        	l=(z*l+i)%m;
		}
		if(l!=r){
			r=(r*z+i)%m;
			q++;
		}
        printf("Case %d: %d\n",p,c-q);
        scanf("%d %d %d %d",&z,&i,&m,&l);
    }

    return 0;
}
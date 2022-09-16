#include<stdio.h>
#include<stdlib.h>
int main(){
    int z,i,m,l,g[50000],x,p=0,c=0,r,q,qq;
    scanf("%d %d %d %d",&z,&i,&m,&l);
    while(z!=0 && i!=0 && m!=0 && l!=0){
    	p++;
    	c=0;
    	r=l;
    	q=0;
        for(x=0;x<=50000;x++)
            g[x]=0; 
        while(g[l]==0){
        	c++;
        	g[l]++;
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
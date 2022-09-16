#include<stdio.h>
#include<stdlib.h>
int main(){
    char a[30],b[30];
    int x,x1,y,y1,i;
    float q,p,c;
    while(gets(a)&&gets(b)){ 
    	x=0;
    	y=0;
    	x1=0;
    	y1=0;
		for(i=0;a[i]!='\0';i++){
        	if(a[i]>='A' && a[i]<='Z')
           		x+=a[i]-'A'+1;
       		if(a[i]>='a' && a[i]<='z')
            	x+=a[i]-'a'+1;
   		}
        while(x>=10){
        	while(x!=0){
            	x1+=x%10;
            	x/=10;
        	}
        	x=x1;
        	x1=0;
    	}
    	for(i=0;b[i]!='\0';i++){
        	if(b[i]>='A' && b[i]<='Z')
            	y+=b[i]-'A'+1;
        	if(b[i]>='a' && b[i]<='z')
           		y+=b[i]-'a'+1;
    	}
   		while(y>=10){
        	while(y!=0){
            	y1+=y%10;
            	y/=10;
        	}
        	y=y1;
        	y1=0;
    	}
    	p=x;
    	q=y;
        if(p>q)
            c=q/p*100;
        else
            c=p/q*100;
        printf("%.2f %%\n",c);
    }
    return 0;
}
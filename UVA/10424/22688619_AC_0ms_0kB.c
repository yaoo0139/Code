#include<stdio.h>
#include<stdlib.h>
int check(char a[30]){
	int x=0,x1=0,i;
	for(i=0;a[i]!='\0';i++){
            if(a[i]>=65 && a[i]<=90){
                x+=a[i]-64;
            }
            if(a[i]>=97 && a[i]<=122){
                x+=a[i]-96;
            }
    }
    while(x>=10){
        while(x!=0){
            x1+=x%10;
            x/=10;
        }
        x=x1;
        x1=0;
    }
    return x;
}
int main(){
    char a[30],b[30];
    float x,y,c;
    while(gets(a)&&gets(b)){ 
		x=check(a);
		y=check(b);     
        if(x>y)
            c=y/x*100;
        else
            c=x/y*100;
        printf("%.2f %%\n",c);
    }
    return 0;
}
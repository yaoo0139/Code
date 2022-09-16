#include<stdio.h>
#include<stdlib.h>
char a[20],qq;
int n;
void HD(int j,int h){
	int i,l,k;
	if (h>1){
		for(i=n-j;i<=n-1;i++){
			if(a[n-j]=='1')
				break;
			if(a[i]=='1'){
				a[i-1]='1';
				a[i]='0';
				puts(a);
				HD(n-i,h-1);
				i=n-j-1;
			}
		}
		for(i=n-1;i>=n-j;i--)
			a[i]='0';
		for(i=n-1;i>=n-h;i--)
			a[i]='1';
	}
	else{
		for(i=n-j;i<=n-1;i++){
			if(a[n-j]=='1')
				break;
			if(a[i]=='1'){
				a[i-1]='1';
				a[i]='0';
				puts(a);
				i=n-j-1;
			}
		}
		for(i=n-1;i>=n-j;i--)
			a[i]='0';
		for(i=n-1;i>=n-h;i--)
			a[i]='1';
	}
	return ;
}
int main(){
	int i,t,h,l=0;
	scanf("%d",&t);
	while(t--){
		if(l)
			printf("\n");
		scanf("%d %d",&n,&h);
		a[n]='\0';
		for(i=n-1;i>=0;i--)
			a[i]='0';
		for(i=n-1;i>=n-h;i--)
			a[i]='1';
		puts(a);
		
		for(i=0;i<=n-1;i++){
			if(a[0]=='1')
				break;
			if(a[i]=='1'){
				a[i-1]='1';
				a[i]='0';
				puts(a);
				HD(n-i,h-1);
				i=0;
			}
		}
		l=1;
	}
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
char a[20];
int n;
void HD(int j,int h){
	int i,l,k;
	for(i=n-j;i<=n-1;i++){
		if(a[n-j]=='1')
			break;
		if(a[i]=='1'){
			a[i-1]='1';
			a[i]='0';
			puts(a);
			if(h>1)
				HD(n-i,h-1);
			i=n-j-1;
		}
	}
	for(i=n-1;i>=n-j;i--)
		a[i]='0';
	for(i=n-1;i>=n-h;i--)
		a[i]='1';
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
		HD(n,h); 
		l=1;
	}
	return 0;
}
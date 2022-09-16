#include <stdio.h>
#include <stdlib.h>
int main (){
	long long int n=2,t=0,i,j,b;
	char a[50];
	scanf("%s",&a);
	for (i=0;a[i]!='\0';i++){
	}
	while(a[0]!='0' || a[1]!='\0'){
		for (j=i-1;j>=0;j--){
			b=(a[j]-'0');
			t +=b*(n-1);
			n=n*2;
		}
		printf("%lld\n",t);
		n=2;
		t=0;
		scanf("%s",&a);
		for (i=0;a[i]!='\0';i++){
		}
	}
	return 0;
}

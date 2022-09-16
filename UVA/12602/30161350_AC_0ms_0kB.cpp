#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int cas;
	cin>> cas;
	while(cas--){
		char str[5];
		char hold;
		int n;
		gets(str);
		scanf("%[^-]%c%d",str, &hold,&n);
		int sum;
		sum = (int)(str[0] - 'A') * 26 * 26 + (str[1] - 'A') * 26 + str[2] - 'A';
		if(abs(sum - n) <= 100)
			puts("nice");
		else
			puts("not nice");

	}
	return 0;
}
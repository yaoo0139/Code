//UVA-10018
#include<stdio.h>
#include<string.h>
void reverse(char num[]){
	int L = strlen(num);
	char hold[15];
	for(int i = L - 1, j = 0; i >= 0; i--, j++)
		hold[j] = num[i];
	hold[L] = 0;
	for(int i = 0; i < L; i++)
		num[i] = hold[i];
	return;
}
//integer to character
long long itoc(char num[]){
	int L = strlen(num);
	long long sum = 0;
	for(int i = L - 1; i >= 0; i--)
		sum = (long long)sum * 10 + num[i] - '0';
	return sum;
}
//character to integer
void ctoi(long long num, char hold[]){
	int counter = 0;
	while(num != 0){
		hold[counter++] = num % 10 + '0';
		num = num / 10;
	}
	hold[counter] = 0;
	reverse(hold);
}
int palindrome(char num[]){
	int L = strlen(num);
	for(int i = 0, j = L - 1; i <= L / 2; i++, j--){
		if(num[i] != num[j])
			return 0;
	}
	return 1;
}
int main(){
	int t;
	char num[15];
	scanf("%d", &t);
	gets(num);
	while(t--){
		long long a, b;
		int counter = 0;
		gets(num);
		do{
			counter++;
			a = itoc(num);
			reverse(num);
			b = itoc(num);
			a = a + b;
			ctoi(a, num);
		}while(!palindrome(num));
		printf("%d ", counter);
		puts(num);
	}

	return 0;
}
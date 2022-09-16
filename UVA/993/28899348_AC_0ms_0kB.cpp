#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>> t;
	int c[10];
    while(t--){
	    memset(c, 0, sizeof(c));
	    int n;
	    cin>> n;
	    if(n==1){
	    	puts("1");
	    	continue;
	    }
	    while(n%2==0){
	    	n/=2;
	    	c[2]++;
	    }
	    while(n%3==0){
	    	n/=3;
	    	c[3]++;
	    }
	    while(n%5==0){
	    	n/=5;
	    	c[5]++;
	    }
	    while(n%7==0){
	    	n/=7;
	    	c[7]++;
	    }
	    if(n!=1){
	    	puts("-1");
	    	continue;
	    }

	    c[9] = c[3]/2;
	    c[3] = c[3]%2;

	    c[8] = c[2]/3;
	    c[2] = c[2]%3;

	    int l = min(c[2], c[3]);
	    c[6] = l;
	    c[2] -= l;
	    c[3] -= l;

	    c[4] = c[2]/2;
	    c[2] = c[2]%2;

	    for(int i=1;i<10;i++){
	    	while(c[i]--)
	    		cout<<i;
	    }
	    cout<<endl;
    }
    return 0;
}
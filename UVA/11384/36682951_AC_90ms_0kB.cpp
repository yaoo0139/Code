#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>> n){
    	cout<<(int)(log(n)/log(2)+1)<<endl;
    }
    return 0;
}
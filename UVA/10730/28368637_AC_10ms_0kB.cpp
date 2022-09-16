#include<bits/stdc++.h>
using namespace std;
int n , num[10010];
int pos[10010];
bool solve(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            int value = 2*num[i]-num[j];  
            if(value >= 0 && value < n && pos[value] > i)   
              return true; 
        }
    }
    return false;
}
 
int main(){
    char str[10];
    while(scanf("%s" , str)){
        if(str[0] == '0') 
            break;
        sscanf(str , "%d:" , &n);
        for(int i = 0 ; i < n ; i++){
           	cin>> num[i];
            pos[num[i]] = i;
        }
       	cout<<(solve() ? "no" : "yes")<<endl;
    }
    return 0;
}
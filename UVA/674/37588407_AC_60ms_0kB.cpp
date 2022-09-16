#include<bits/stdc++.h>
using namespace std;
int main(){
    int value[5] ={1, 5, 10, 25, 50};
    int ans[7500] = {0};
    ans[0] = 1;
    for(int i=0; i<5; i++){
        for(int j=0; j<7500; j++){
            if(j + value[i] > 7489)
                break;
            ans[j+value[i]] += ans[j];
        }
    }
    int n;
    while(cin>> n){
        cout<< ans[n]<< endl;
    }

}
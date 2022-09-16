#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans[100500] = {0};
    for(int i=1; i <= 100000; i++){
        int hold = i;
        int x = i;
        while(hold != 0){
            x += hold % 10;
            hold /= 10;
        }
        if(ans[x] == 0)
            ans[x] = i;
    }
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        cout<< ans[n]<< endl;
    }
}
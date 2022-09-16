#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        int arr[10] = {0} ;
        for(int i=1; i<=n; i++){
            int x = i;
            while(x != 0){
                arr[x%10]++;
                x /= 10;
            }
        }
        cout<< arr[0];
        for (int i = 1; i < 10; ++i)
            cout<< " "<< arr[i];
        cout<< endl;
    }
    return 0;
}
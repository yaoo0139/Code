#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b ;
    int n;
    while(cin>> n){
        cin>> a>> b;
        for(int i=0;i<n;i++)
            cout<<a[i]<<b[i];
        cout<<endl;
    }
}

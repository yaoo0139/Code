#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int day, n;
        bool work[4000] = {0};
        int party[105];
        int counter = 0;
        cin>> day>> n;
        for(int i=0;i<n;i++)
            cin>>party[i];
        for(int i=0;i<n;i++){
            for(int k=party[i];k<=day;k+=party[i])
                work[k] = true;
        }
        for(int i=6;i<=day; i+=7)
            work[i] = work[i+1] = false;
        for(int i=1;i<=day;i++){
            if(work[i])
                counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}

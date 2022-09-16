#include<bits/stdc++.h>
using namespace std;
int main(){

    int n, k;
    while(cin>> n>> k){
        vector<int> v;
        v.resize(n+1);
        int sum = 0;
        int minn = 0;
        for(int i=0; i<v.size(); i++){
            cin>> v[i];
            sum += v[i];
            minn = max( minn, v[i]);
        }
        int l = minn, r = sum;
        int maxx = 0;

        while(l < r){

            int mid = (l + r) / 2;
            int day = 0;
            int dis = v[0];
            for(int i=1; i<v.size(); i++){
                if(dis + v[i] > mid){
                    day ++;
                    dis = v[i];
                }
                else
                    dis += v[i];
            }
            if(day > k)
                l = mid + 1; 
            else
                r = mid;
            
        }
        cout<< l<< endl;
    }
    return 0;
}
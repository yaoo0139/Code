#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    string str;
    getline(cin, str);
    while(t--){
        getline(cin, str);
        stringstream ss;
        ss << str;
        vector<int> v;
        int x;
        int sum = 0;
        while(ss>> x){
            v.push_back(x);
            sum += x;
        }
        if(sum % 2){
            puts("NO");
            continue;
        }
        bool ans[205] = {0};
        ans[0] = true;
        for(int i:v){
            for(int j=sum; j>=i; j--){
                if(ans[j-i])
                    ans[j] = true;
            }
        }
        if(ans[sum / 2])
            puts("YES");
        else
            puts("NO");

    }
}
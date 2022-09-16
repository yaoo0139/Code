#include<bits/stdc++.h>
using namespace std;

struct correct{
    int a;
    int b;
};
correct cmp(string num, string ans){
    //cout<< num<< " "<<ans<<endl;
    int a, b;
    a = b = 0;
    bool num_used[10] = {0};
    bool ans_used[10] = {0};
    for(int i=0; i<4; i++){
        if(num[i] == ans[i]){
            a++;
            ans_used[i] = num_used[i] = true;
        }
    }
    //cout<<"a = "<<a <<" b = "<<b << endl;
    for(int i=0; i<4; i++){
        if(ans_used[i])
            continue;
        for(int j=0; j<4; j++){
            if(num_used[j])
                continue;
            if(ans[i] == num[j]){
                b++;
                ans_used[i] = true;
                num_used[j] = true;
                break;
            }
        }
    }
    //cout<<"a = "<<a <<" b = "<<b << endl;
    return correct{a, b};
}
string tostr(int x){
    string str = to_string(x);
    while(4 - str.size()){
        str = "0" + str;
    }
    return str;
}
int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        vector<string> num, ans;
        vector<correct> v;
        cin>> n;
        while(n--){
            string str;
            string s;
            int a, b;
            cin>> str>> s;
            a = s[0] - '0';
            b = s[2] - '0';
            num.emplace_back(str);
            v.emplace_back(correct{a, b});
        }
        for(int i=0; i<10000; i++){
            bool flag = true;
            string str = tostr(i);
            for(int j = 0; j < num.size(); j++){
                correct hold = cmp(num[j], str);
                if(hold.a != v[j].a || hold.b != v[j].b){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.emplace_back(str);
            
            if(ans.size() > 1)
                break;
        }
        if(ans.size() == 0)
            cout<<"impossible\n";
        else if(ans.size() > 1)
            cout<<"indeterminate\n";
        else
            cout<< ans[0]<< endl;
    }
    return 0;
}
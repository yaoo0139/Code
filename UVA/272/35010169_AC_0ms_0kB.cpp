#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    bool flag = true;
    while(getline(cin, str)){
        for(int i=0; i<str.size(); i++){
            if(str[i] == '\"'){
                if(!flag)
                    cout<<"\'\'";
                else
                    cout<<"``";
                flag = !flag;
            }
            else
                cout<< str[i];
        }
        cout<< endl;
    }
}
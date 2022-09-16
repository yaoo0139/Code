#include<bits/stdc++.h>
using namespace std;
int main(){

    string str;
    set<string> s;
    s.clear();
    string hold;
    hold.clear();
    while(getline(cin, str)){
        for(int i=0; i<str.size(); i++){
            if(isalpha(str[i])){
                hold.push_back(tolower(str[i]));
            }
            else if(hold.size() != 0){
                s.insert(hold);
                hold.clear();
            }
            else
                continue;
        }
        if(hold.size() != 0){
	       	s.insert(hold);
	        hold.clear();
	    }
    }
    for(auto i : s)
        cout<< i<<endl;

    return 0;
}

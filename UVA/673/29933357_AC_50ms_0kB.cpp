#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	stack<char> s;
	string str;
	cin>> t;
	getline(cin, str);
	while(t--){
	
		while(!s.empty())
			s.pop();
		getline(cin, str);
		bool flag = true;
		for(int i=0;i<str.length() && flag;i++){
			if(str[i] != ')' && str[i] != ']')
				s.push(str[i]);
			else if(str[i] == ')'){
				if(s.empty()){
					flag = false;
					break;
				}
				char hold = s.top();
				s.pop();
				if(hold != '(')
					flag = false;
			}
			else if(str[i] == ']'){
				if(s.empty()){
					flag = false;
					break;
				}
				char hold = s.top();
				s.pop();
				if(hold != '[')
					flag = false;
			}
		}
		if(!s.empty())
			flag = false;

		if(flag)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
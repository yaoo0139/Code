#include<bits/stdc++.h>
using namespace std;
int main(){
	string str, str1;
	while(cin>> str>> str1){
		if(str.size() < str1.size())
			swap(str, str1);

		int ans = 1e9;

		for(int i=0; i <= str.size() - str1.size(); i++){
			bool flag = true;
			for(int j=0; j<str1.size(); j++){
				if(str[i+j] - '0' + str1[j] - '0' > 3){
					flag = false;
					break;
				}
			}
			if(flag){
				ans = str.size();
				break;
			}
		}
		if(ans != 1e9){
			cout<< ans<< endl;
			continue;
		}
		
		for(int i=0,j=str1.size()-1; i < str1.size(); i++,j--){
			bool flag = true;;
			for(int a = 0, b = j;a <= i; a++, b++){
				
				if(str[a]-'0' + str1[b]-'0' > 3){
					flag = false;
					break;
				}
			}
		
			if(flag){
				ans = min(ans, (int)str.size() + j);
			}
		}

		for(int i= str.size() - str1.size()+1, counter = 1;i < str.size(); i++, counter++){
			bool flag = true;
			for(int j=0; j + i < str.size(); j++){
				if(str[i+j] - '0' + str1[j] - '0' > 3){
					flag = false;
					break;
				}
			}
			if(flag){
				ans = min( ans, (int)str.size() + counter);
				break;
			}
		}
		if(ans == 1e9)
			cout<< str.size() + str1.size()<< endl;
		else
			cout<< ans<< endl;
	}
	return 0;
} 

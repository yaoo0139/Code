#include<bits/stdc++.h>
using namespace std;
bool chk(string str){
	for(int i=0, j = str.size() - 1; i <= str.size()/2; i++, j--){
		if(str[i] != str[j])
			return false;
	}
	return true;
}
int main(){
	int t;
	cin>> t;
	while(t--){
		int arr[30] = {0};
		string str;
		cin>> str;
		for(int i=0; i<str.size(); i++)
			arr[str[i] - 'a']++;
		int counter = 0;
		for(int i=0; i<26; i++){
			if(arr[i] % 2)
				counter++;
		}
		if(counter > 1){
			puts("Impossible");
			continue;
		}
		counter = 0;
		while(!chk(str)){
		
			int L = str.size();
			if(arr[str[0] - 'a'] == 1){
				swap(str[0], str[1]);
				counter++;
				continue;
			}
			for(int j = L-1; j >= 0; j--){
				if(str[0] == str[j]){
					counter += L - j - 1;
					string hold1 = str.substr(1, j - 1);
					string hold2 = str.substr(j + 1, str.size() - j - 1);
					arr[str[0] - 'a'] -= 2;
					str = hold1 + hold2;
					break;
				}
			}
			
		}
		cout<< counter<< endl;
	}
	return 0;
}

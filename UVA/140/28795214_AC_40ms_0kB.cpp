#include<bits/stdc++.h>
using namespace std;
int main(){
	string r;
	while(cin>> r && r[0] != '#'){
		bool flag = false;
		bool G[30][30] = {0};
		vector<char> node;
 		char hold;
 		int mini = 10;
 		for(int i=0;i<r.size();i++){
 			if(r[i] == ':'){
 				flag = true;
 				continue;
 			}
 			if(r[i] == ';'){
 				flag = false;
 				continue;
 			}
 			if(!flag){
 				hold = r[i];
 				auto it = find(node.begin(), node.end(), r[i]);
 				if(it == node.end())
 					node.push_back(r[i]);
 			}
 			else{
 				auto it = find(node.begin(), node.end(), r[i]);
 				if(it == node.end())
 					node.push_back(r[i]);
 				G[hold-'A'][r[i]-'A'] = true;
 				G[r[i]-'A'][hold-'A'] = true;
 			}

 		}
 		sort(node.begin(),node.end());
 		vector<char> v;
 		do{
 			int ma = 0;
 			for(int i=0;i<node.size();i++){
 				int now = node[i] - 'A';
 				for(int k=0;k<node.size();k++){
 					if(k==i)
 						continue;
 					if(G[now][node[k]-'A']){
 						int dis = abs(k-i);
 						ma = max(dis, ma);
 					}
 				}
 			}
 			if(mini > ma){
 				v = node;
 				mini = min(mini, ma);
 			}
 		}while(next_permutation(node.begin(),node.end()));
 		for(char c : v)
 			cout<<c<<" ";
 		cout<<"-> "<<mini<<endl;
	}
}
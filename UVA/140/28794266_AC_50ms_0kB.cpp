#include<bits/stdc++.h>
using namespace std;
int main(){
	string r;
	while(cin>> r && r[0] != '#'){
		bool flag = false;
		vector<char> G[30];
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
 				it = find(G[hold-'A'].begin(), G[hold-'A'].end(), r[i]);
 				if(it == G[hold-'A'].end())
 					G[hold-'A'].push_back(r[i]);
 				it = find(G[r[i]-'A'].begin(), G[r[i]-'A'].end(), hold);
 				if(it == G[r[i]-'A'].end())
 					G[r[i]-'A'].push_back(hold);
 			}

 		}
 		sort(node.begin(),node.end());
 		for(int i=0;i<26;i++){
 			if(G[i].size()){
 				sort(G[i].begin(),G[i].end());
 			}
 		}
 		vector<char> v;
 		do{
 			int ma = 0;
 			for(int i=0;i<node.size();i++){
 				int now = node[i] - 'A';
 				for(int k=0;k<G[now].size();k++){
 					auto it = find(node.begin(), node.end(), G[now][k]);
 					if(it != node.end()){
 						int dis = abs(distance(node.begin(), it) - i);
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
#include<bits/stdc++.h>
using namespace std;
bool flag;
int n, g;
void dfs(int now, int dis){
	if(flag)
		return;
	if(now  == g){
		flag = true;
		return;
	}
	if(now + dis <= n)
		dfs(now + dis, dis + 2);
	if(now - dis > 0 )
		dfs(now - dis, dis + 2);
}
int main(){
	while(cin>> n>> g && g!=0 && n!=0){
		flag = false;
		if(n>=49)
			flag = true;
		dfs(1 , 3);
		if(!flag)
			puts("Don't make fun of me!");
		else
			puts("Let me try!");
	}
	return 0;
}
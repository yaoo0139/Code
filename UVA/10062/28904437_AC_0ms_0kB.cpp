#include<bits/stdc++.h>
using namespace std;
struct node
{
	int asc;
	int val;
	bool operator<(const node &rhs)const{
		return val > rhs.val || (val == rhs.val && asc < rhs.asc);
	}
};
int main()
{
	string str;
	int l=0;
	while(getline(cin, str)){
		if(l)
			puts("");
		priority_queue<node> pq;
		map<int, int> m;
		for(int i=0;i<str.size();i++)
			m[str[i]]++;
		for(auto i : m)
			pq.push(node{i.first, i.second});
		while(!pq.empty()){
			node hold = pq.top();
			printf("%d %d\n",hold.asc, hold.val);
			pq.pop();
		}
		l=1;
	}
    return 0;
}
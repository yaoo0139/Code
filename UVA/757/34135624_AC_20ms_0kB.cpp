#include <bits/stdc++.h>
using namespace std;
struct Lake
{
	int fish;
	int idx;
	bool operator<(const Lake &rhs)const{
		return fish < rhs.fish || (fish == rhs.fish && idx > rhs.idx);
	}
};
int main(){
	int n;
	int h;
	int l = 0;
	while(cin>> n && n){
		if(l)
			puts("");
		l=1;
		cin>> h;
		vector<Lake> v;
		vector<int> reduce, move;
		int anstime[30] = {0};
		int ans = -1;
		for(int i=1;i<=n;i++){
			int x;
			cin>> x;
			v.push_back(Lake{x, i});
		}
	
		for(int i=0;i<n;i++){
			int x;
			cin>> x;
			reduce.push_back(x);
		}

		move.push_back(0);
		for(int i=1;i<n;i++){
			int x;
			cin>> x;
			move.push_back(x);
		}
		for(int i=0; i < move.size(); i++){
			int arr[30] = {0};
			int sum = 0;
			priority_queue<Lake> pq;
			int t = h * 12;
			for(int j = 0; j <= i; j++){
				t -= move[j];
				pq.push(v[j]);
			}	
			for(int k=0; k<t;k++){
				Lake tmp = pq.top();
				pq.pop();
				sum += tmp.fish;
				arr[tmp.idx] ++;
				if(tmp.fish - reduce[tmp.idx-1] < 0)
					pq.push( Lake{0, tmp.idx});
				else
					pq.push( Lake{tmp.fish - reduce[tmp.idx-1], tmp.idx});
			}
			if(ans < sum){
				ans = sum;
				for(int i=1;i<=n;i++)
					anstime[i] = arr[i];
			}	
		}
		cout<< anstime[1] * 5;
		for(int i=2;i<=n;i++)
			cout<<", "<<anstime[i] * 5;
		cout<< endl;
		cout<<"Number of fish expected: "<< ans<< endl;	
	}
    return 0;
}

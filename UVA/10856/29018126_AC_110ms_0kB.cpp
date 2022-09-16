#include<bits/stdc++.h>
using namespace std;
bool prime[3000500];
int arr[3000500];
int ans[3000500];
vector<int> p;
void init(){
	for(int i=2;i<=3000000;i++){
		if(!prime[i]){
			p.push_back(i);
			for(int j=i+i;j<=3000000;j+=i)
				prime[j] = true;
		}
	}
	for(int i=2;i<=3000000;i++){
		if(!prime[i]){
			arr[i] = 1;
			ans[i] = ans[i-1] + 1;
			continue;
		}
		for(int x : p){
			if(i % x == 0){
				arr[i] = arr[i/x] + arr[x];
				ans[i] = ans[i-1] + arr[i];
				break;
			}
		}	
	}
	return;
}
int main()
{
	int t;
	int counter = 1;
	init();
	while(cin>> t && t >= 0){
		printf("Case %d: ", counter++);
		if(t==0){
			puts("0!");
			continue;
		}
		int l = 0;
		int r = 3000000;
		bool flag = false;
		while(l<=r){
			int mid = (l+r) / 2;
			if(ans[mid] == t){
				printf("%d!\n", mid);
				flag = true;
				break;
			}
			else if(l == r){
				break;
			}
			else if(ans[mid] < t){
				l = mid + 1;
			}
			else if(ans[mid] > t){
				r = mid;
			}
		}
		if(!flag)
			printf("Not possible.\n");
	}
    return 0;
}
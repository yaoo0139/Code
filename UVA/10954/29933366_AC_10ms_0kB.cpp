#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, f, l, x, y, z;
	priority_queue<int,vector<int>,greater<int> > num;

	while(~scanf("%d", &t) && t != 0){
		int sum = 0;
		int count = 0;

		for (int i = 1; i <= t; ++i){
			cin >> y;
			num.push(y);
		}

		while(num.size() != 1){
			f = num.top();
			num.pop();
			l = num.top();
			num.pop();

			x = f + l;
			sum += x;
			count++;

			num.push(x);
		}
		num.pop();

		printf("%d\n", sum);
	}
	return 0;
}
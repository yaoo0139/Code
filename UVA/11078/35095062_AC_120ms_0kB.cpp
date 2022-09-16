#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[100500];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int ans = arr[0] - arr[1];
		int maxs = arr[0];
		for (int i = 1; i < n; i++){
			ans = max(ans, maxs - arr[i]);
			maxs = max(maxs, arr[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
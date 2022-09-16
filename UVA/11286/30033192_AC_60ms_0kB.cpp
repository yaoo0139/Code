#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> v;
	while(cin >> n && n) {
		map< vector<int>, int> m;

		for(int i = 0; i < n; i++) {


			// 1. 儲存5個數字，然後排序
			v.clear();
			for(int j = 0; j < 5; j++) 
			{
				int num;
				cin >> num;
				v.push_back(num);
			}

			sort(v.begin(), v.end());

			m[v]++;



		}

		// 4. 尋找最多人選課的組合有多少人
		int maximum = 0;
		for(auto i : m) maximum = max(i.second, maximum);


                // 5. 計算最多人的組合總共有多少人
		int sum = 0;
		for(auto i : m) 
			if(i.second == maximum) sum += maximum;

		cout << sum << endl;
	}

	return 0;
}
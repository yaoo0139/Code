#include<bits/stdc++.h>
using namespace std;
struct Line{
	int x1;
	int y1;
	int x2;
	int y2;
	bool operator<(const Line rhs)const{
		return max(y1, y2) > max(rhs.y1, rhs.y2);
	}
};
int main(){
	int t;
	cin>> t;
	int c = 0;
	while(t--){
		int l;
		cin>> l;
		if(c)
			puts("");
		c = 1;
		vector<Line> line;
		while(l--){
			int a, b, c, d;
			cin>> a>> b>> c>> d;
			line.push_back(Line{a, b, c, d});
		}
		sort(line.begin(), line.end());
		int query;
		cin>> query;
		while(query--){
			int qx, qy;
			cin>> qx>> qy;
			for(auto i : line){
				double ny = 1e10;
				if(qx <= max(i.x1, i.x2) && min(i.x1, i.x2) <= qx){
					int tx = i.x1 - i.x2;
					int ty = i.y1 - i.y2;
					double n = (double)(qx - i.x2) / tx;
					ny = (double)i.y2 + n * ty;
				}
				if(qy > ny){
					if(i.y1 > i.y2){
						qx = i.x2;
						qy = i.y2; 
					}
					else{
						qx = i.x1;
						qy = i.x2;
					}
				}
			}
			cout<< qx<< endl;
		}
	}
	return 0;
}
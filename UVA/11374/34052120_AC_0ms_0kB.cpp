#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 505;
const LL INF = 1e18;
struct Edge{
	int to;
	LL cost;
	bool operator<(const Edge rhs) const{
		return cost > rhs.cost;
	}
};
int n;
LL dis[MAXN], dis1[MAXN];
int from[MAXN], from1[MAXN];
vector<Edge> G[MAXN];
void init(){
	for(int i=0; i <=n ;i++){
		G[i].clear();
		dis[i] = dis1[i] = INF;
		from[i] = from1[i] = -1;
	}
}
void dijkstra(int st, int ed = -1){
	priority_queue<Edge> pq;
	pq.emplace(Edge{st, 0});
	dis[st] = 0;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.to == ed)
			return;
		if(now.cost > dis[now.to]){
			continue;
		}
		for(auto &e : G[now.to]){
			if(dis[e.to] > now.cost + e.cost){
				dis[e.to] = now.cost + e.cost;
				from[e.to] = now.to;
				pq.emplace(Edge{e.to, dis[e.to]});
			}
		}
	}
}
void dijkstra1(int st, int ed = -1){
	priority_queue<Edge> pq;
	pq.emplace(Edge{st, 0});
	dis1[st] = 0;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.to == ed)
			return;
		if(now.cost > dis1[now.to]){
			continue;
		}
		for(auto &e : G[now.to]){
			if(dis1[e.to] > now.cost + e.cost){
				dis1[e.to] = now.cost + e.cost;
				from1[e.to] = now.to;
				pq.emplace(Edge{e.to, dis1[e.to]});
			}
		}
	}
}
void traceback(int x){
	if(from[x] != -1)
		traceback(from[x]);
	if(from[x] == -1)
		cout<<x;
	else
		cout<<" "<<x;
	return;
}
void traceback1(int x){
	if(from1[x] == -1){
		cout<<" "<<x<< endl;
		return;
	}
	else{
		cout<<" "<<x;
		traceback1(from1[x]);
	}
}
int main(){
	int s, t;
	int l = 0;
	while(cin>> n>> s>> t){
		if(l)
			puts("");
		l = 1;
		init();
		int k;
		cin>> k;
		for(int i=0; i<k; i++){
			int u, v ,w;
			cin>> u>> v>> w;
			G[u].emplace_back(Edge{v, w});
			G[v].emplace_back(Edge{u, w});
		}
		dijkstra(s, t);
		dijkstra1(t, s);
		int cu = -1, cv = -1;
		LL cost = dis[t];
		cin>> k;
		int u, v, w;
		for(int i=0; i<k; i++){
			cin>> u>> v>> w;
			if(dis[u] + w + dis1[v] < cost){
				cost = dis[u] + w + dis1[v];
				cu = u;
				cv = v;
			}
			if(dis[v] + w + dis1[u] < cost){
				cost = dis[v] + w + dis1[u];
				cu = v;
				cv = u;
			}
		}
		if(cu != -1){
			traceback(cu);
			traceback1(cv);
			cout<< cu<< endl;
		}
		else{
			traceback(t);
			cout<< endl;
			cout<<"Ticket Not Used\n";
		}

		cout<< cost<< endl;
	}
	return 0;
}

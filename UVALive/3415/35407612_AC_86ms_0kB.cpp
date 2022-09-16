#include<bits/stdc++.h>
using namespace std;
struct People{
    int h;
    string sex;
    string style;
    string sport;
};

int n;
vector<People> student;
vector<int> G[515];
int match[515];
bool used[515];

void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

bool dfs(int u){
    used[u] = true;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        int w = match[v];
        if(w < 0 || !used[w] && dfs(w)){
            match[u]=v;
            match[v]=u;
            return true;
        }
    }
    return false;
}
int bipartite_matching(){
    int ans = 0;
    memset(match, -1, sizeof(match));
    for(int v = 0; v < n; v++){
        if(match[v] < 0){
            memset(used, 0, sizeof(used));
            if(dfs(v))
                ans++;
        }
    }
    return ans;
}
bool check(int a,int b){
    if(abs(student[a].h - student[b].h) > 40 || student[a].style != student[b].style || student[a].sport == student[b].sport)
        return true;
    return false;
}

int main()
{
    int T;
    cin>> T;
    while(T--){

        student.clear();
        for(int i=0;i<515;i++)
            G[i].clear();
        cin>> n;
        for(int i=0;i<n;i++){
            int h;
            string sex;
            string style;
            string sport;
            cin>> h>> sex>> style>> sport;
            student.emplace_back(People{h, sex, style, sport});
        }
        for(int i=0;i<n;i++)
        {
            if(student[i].sex=="M"){
                for(int j=0;j<n;j++){
                    if(student[j].sex=="F" && !check(i,j))
                        add_edge(i,j);
                }
            }
        }
        int ans = bipartite_matching();
        cout<< n-ans<< endl;
    }
}
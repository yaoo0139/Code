#include<bits/stdc++.h>
using namespace std;
set<vector<int>> check;
vector<int> m, ans;
bool flag = 0;
int total, n;
void dfs(int sum, int x, int s){
    sum += m[x];
    if(sum > total){
        ans.pop_back();
        return;
    }
    else if (sum == total){
        flag = true;
        if(!check.count(ans)){
            for(int i=0;i<ans.size();i++){
                if(i!=ans.size()-1)
                    cout<<ans[i]<<"+";
                else
                    cout<<ans[i]<<endl;
            }
            check.insert(ans);
        }
        ans.pop_back();
        return;
    }
    for(int i = x+1; i < n; i++){
        if(sum < total){
            ans.push_back(m[i]);
            dfs(sum, i, s+1);
        }
    }
    ans.pop_back();
}
int main(){
    while(cin>> total>> n && total != 0 && n != 0){
        flag = 0;
        check.clear();
        ans.clear();
        m.clear();
        for(int i = 0; i < n; i++){
            int x;
            cin>> x;
            m.push_back(x);
        }
        cout<<"Sums of "<< total<<":"<<endl;
        for(int i=0;i<n;i++){
            ans.push_back(m[i]);
            dfs(0, i, 0);
            ans.clear();
        }
        if(!flag)
            puts("NONE");
    }
    return 0;
}

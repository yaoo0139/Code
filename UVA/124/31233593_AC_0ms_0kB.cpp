#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
string ans;
string str;
bool used[30];
int r[30];
vector<char> G[30];
void dfs(int x, int counter){
    ans.push_back(str[x]);
    if(counter == str.size()){
        cout<<ans<<endl;
        ans.pop_back();
        return;
    }
    used[x] = true;
    for(int i=0;i<str.size();i++){
        if(!used[i] && !r[str[i] - 'a']){
            for(int k=0; k<G[str[i] - 'a'].size(); k++)
                r[G[str[i] - 'a'][k] - 'a']--;
            dfs(i, counter+1);
            for(int k=0; k<G[str[i] - 'a'].size(); k++)
                r[G[str[i] - 'a'][k] - 'a']++;
        }          
    }
    ans.pop_back();
    used[x] = false;
    return;
}
int main(){
    string hold;
    int l = 0;
    while(getline(cin, str)){
        if(l)
            puts("");
        l = 1;

        memset(used, 0, sizeof(used));
        memset(r, 0, sizeof(r));
        ans.clear();
        for(int i=0;i<30;i++)
            G[i].clear();

        stringstream ss;
        ss<< str;
        str.clear();
        char c, ch;
        while(ss>> c)
            str.push_back(c);
        sort(str.begin(), str.end());

        ss.clear();
        getline(cin, hold);
        ss<< hold;
        while(ss>> c>> ch){
            G[c-'a'].push_back(ch);
            r[ch-'a'] ++;
        }
        for(int i=0;i<str.size();i++){
            if(!used[i] && !r[str[i] - 'a']){
                for(int k=0; k<G[str[i] - 'a'].size(); k++)
                    r[G[str[i] - 'a'][k] - 'a']--;
                dfs(i, 1);
                for(int k=0; k<G[str[i] - 'a'].size(); k++)
                    r[G[str[i] - 'a'][k] - 'a']++;
            }  
        }
    }
    return 0;
}
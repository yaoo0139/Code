#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> team[1005];
    queue<int> bteam;
    map<int, int> noodle;
    string s;
    int n;
    int x;
    int cases = 1;
    while(cin>> n && n != 0){
        printf("Scenario #%d\n", cases++);
        bteam = queue<int>() ;
        for(int i=0; i<n ;i++){
            team[i] = queue<int>() ;
            int times;
            cin>> times;
            for(int j=0;j<times;j++){
                cin>> x;
                noodle[x] = i;
            }
        }
        while(cin>> s){
            if(s[0]=='S'){
                puts("");
                break;
            }
            if(s[0]=='E'){
                cin>> x;
                if(team[noodle[x]].size()==0)
                    bteam.push(noodle[x]);
                team[noodle[x]].push(x);
            }
            else if(s[0]=='D'){
                int f = bteam.front();
                cout<<team[f].front()<<endl;
                team[f].pop();
                if(team[f].size() == 0)
                    bteam.pop();
            }
        }
    }
    return 0;
}

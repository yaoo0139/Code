#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> fgroup;
    int n;
    int counter = 0;
    while(cin>> n && n != 0){
        counter++;
        printf("Scenario #%d\n", counter);
        queue<int> bigteam, group[1005];
        while(n--){
            int x;
            cin >> x;
            while(x--){
                int a;
                cin>> a;
                fgroup[a] = n;
            }
        }
        string str;
        while(cin>> str){
            int x;
            if(str == "ENQUEUE"){
                cin>> x;
                if(group[fgroup[x]].size() == 0)
                    bigteam.push(fgroup[x]);
                group[fgroup[x]].push(x);
            }
            else if(str == "DEQUEUE"){
                int hold = bigteam.front();
                cout<<group[hold].front()<<endl;
                group[hold].pop();
                if(group[hold].size() == 0)
                    bigteam.pop();
            }
            else
                break;
        }
        puts("");
    }
}

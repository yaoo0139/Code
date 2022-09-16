#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    map<int, int> m;
    int n;
    m.clear();
    while(cin>> n){
        if(m.find(n) != m.end()){
            m[n] ++;
            continue;
        }
        q.push(n);
        m[n] = 1;
    }
    while(q.size() != 0){
        int f = q.front();
        cout<< f<< " "<<m[f]<<endl;
        q.pop();
    }
    return 0;
}

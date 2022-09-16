#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a;
    int times;
    int l = 0;
    string str;

    set<string> s;
    cin >> times;
    getline(cin, str);
    getline(cin, str);
    while(times--)
    {
        map<string, double> m;
        int counter = 0;
        getline(cin, str);
        while(str.size() != 0){
            counter ++;
            if(!s.count(str)){
                s.insert(str);
                m[str] = 1;
            }
            else
                m[str]++;
            getline(cin, str);
        }
        if(l)
            cout<<endl;
        l=1;
        for(auto iter = m.begin(); iter!=m.end(); iter++){
            cout<<iter->first<<" "<<fixed<<setprecision(4)<<iter->second/counter*100<<endl;
        }
    }
    return 0;
}

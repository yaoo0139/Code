#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> word;
    int x, y;
    string str;
    int value;
    char c;
    while(cin>> x>> y)
    {
        int sum = 0;
        word.clear();
        while(x--)
        {
            cin>> str>> value;
            word[str] = value;
        }
        str.clear();
        for(int i=0; i<y; i++)
        {
            sum = 0;
            while(~scanf("%c",&c))
            {
                if((c >= 'a' && c <='z') || (c >= 'A' && c <='Z')){
                    str.push_back(c);
                    continue;
                }
                auto iter = word.find(str);
                if(iter != word.end())
                    sum += iter->second;
                str.clear();
                if(c == '.')
                    break;
            }
            cout<< sum<< endl;
        }
    }
    return 0;
}

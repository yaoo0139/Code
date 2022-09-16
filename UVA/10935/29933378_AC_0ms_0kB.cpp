#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque <int> num;
    int t, r, k,q;

    while(~scanf("%d", &t) && t != 0)
    {

        cout << "Discarded cards:";
        for (int i = 1; i <= t; ++i)
        {
            num.push_back(i);
        }
        int flag = 0;
        while(num.size() != 1)
        {
            r = num.front();
            if(flag)
            {
                printf(",");
            }
            cout <<" " <<  r;
            num.pop_front();
            r = num.front();
            num.pop_front();
            num.push_back(r);
            flag = 1;
        }
        puts("");
        r = num.front();
        num.pop_front();

        cout << "Remaining card: " << r << endl;
    }
    return 0;
}
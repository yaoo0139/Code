#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack <int> num;
    queue <int> number;
    int n,z;
    int t[1000000];

    while(~scanf("%d", &n) && n != 0)
    {

        while(1)
        {

            while(!number.empty())
            {
                number.pop();
            }
            while(!num.empty())
            {
                num.pop();
            }

            for (int i = 0; i < n; i++)
            {
                scanf("%d", &t[i]);
                if(t[0] == 0)
                {
                    break;
                }
            }
            if(t[0] == 0)
            {
                break;
            }

            for(int i = 1; i <= n; i++)
            {
                number.push(i);
            }
            num.push(0);
            for (int i = 0; i < n; ++i)
            {
                if(num.top() == t[i])
                {
                    num.pop();
                    continue;
                }
                while(number.front() != t[i] && !number.empty())
                {
                    int r = number.front();
                    number.pop();
                    num.push(r);

                }
                if(!number.empty() && number.front() == t[i])
                {
                    number.pop();
                    continue;
                }
            }

            if(number.empty() && num.top() == 0)
            {
                cout << "Yes\n";
            }

            else
            {
                cout << "No\n";
            }
        }
        puts("");

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct area
{
    int l;
    int r;
};
bool cmp(area a, area b)
{
    return a.l < b.l;
}
int main()
{
    int L, n;
    int right, nowr;
    while(cin>> L>> n && L!=0 || n!=0)
    {
        bool flag = 1;
        int point, dis;
        vector<area> p;
        p.clear();
        for(int i=0; i<n; i++)
        {
            cin >> point >>dis;
            p.push_back(area{point-dis,point+dis});
        }
        sort(p.begin(), p.end(), cmp);
        if(p[0].l>0)
        {
            puts("-1");
            continue;
        }
        nowr = p[0].r;
        right = 0;
        int counter = 0;
        if(nowr >= L)
        {
            counter += n-1;
        }
        else
        {
            for(int i=1; i<n; i++)
            {
                if(p[i].l <= right && p[i].r > nowr)
                {
                    counter++;
                    nowr = p[i].r;
                }
                else if(p[i].l >right && p[i].l <= nowr)
                {
                    right = nowr;
                    nowr = p[i].r;
                }
                else if(p[i].l > nowr)
                {
                    flag = 0;
                    break;
                }
                else
                    counter++;
                if(nowr >= L)
                {
                    counter += n-i-1;
                    break;
                }

            }
        }
        if(flag && nowr >= L)
            cout<<counter<<endl;
        else
            puts("-1");
    }


    return 0;
}

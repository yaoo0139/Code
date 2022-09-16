#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack <int> sta;
    queue <int> que;
    priority_queue <int, vector<int>, less<int> > pq;
    bool s,q,p;
    int type, obj;
    int n;

    while(~scanf("%d", &n))
    {
        int counter =0;
        s=q=p=true;
        while(!sta.empty())
            sta.pop();
        while(!que.empty())
            que.pop();
        while(!pq.empty())
            pq.pop();
        for(int i=1; i<=n; i++)
        {
            cin >> type>> obj;
            if(s || p || q)
            {
                if(type==1)
                {
                    counter++;
                    sta.push(obj);
                    que.push(obj);
                    pq.push(obj);
                }
                else if(counter >0)
                {
                    counter--;
                    int check;
                    if(s)
                    {
                        check=sta.top();
                        sta.pop();
                        if(check!=obj)
                            s=false;
                    }
                    if(q)
                    {
                        check=que.front();
                        que.pop();
                        if(check!=obj)
                            q=false;
                    }
                    if(p)
                    {
                        check=pq.top();
                        pq.pop();
                        if(check!=obj)
                            p=false;
                    }
                }
                else
                    s=p=q=false;
            }
        }
        if(!s && !q && !p)
            puts("impossible");
        else if(s && !q && !p)
            puts("stack");
        else if(!s && q && !p)
            puts("queue");
        else if(!s && !q && p)
            puts("priority queue");
        else
            puts("not sure");
    }

    return 0;
}

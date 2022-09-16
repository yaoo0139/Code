//20220316
#include <bits/stdc++.h>
using namespace std;
struct data
{
    int sum, i;
    bool operator<(const data &rhs)const{
        return sum > rhs.sum;
    }
};
int main()
{
    int k;
    int a[1005], b[1005];
    while(cin >> k)
    {
        for(int i=0; i<k; i++)
            cin>> a[i];
        sort(a,a+k);
        for(int j=1; j<k; j++)
        {
            for(int i=0; i<k; i++)
                cin>> b[i];
            sort(b, b+k);

            priority_queue<data> pq;

            for(int i=0; i<k; i++)
                pq.push(data{a[i]+b[0], 0});

            for(int i=0; i<k; i++)
            {
                data hold = pq.top();
                pq.pop();
                a[i] = hold.sum;
                if(hold.i + 1 < k)
                    pq.push(data{hold.sum - b[hold.i] + b[hold.i+1], hold.i+1});
            }
        }
        for(int i=0; i<k; i++)
        {
            if(i)
                cout<<" ";
            cout<< a[i];
        }
        cout<<endl;
    }
    return 0;
}

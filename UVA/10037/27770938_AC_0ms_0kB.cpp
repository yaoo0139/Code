#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>> t;
    int ch = 0;
    while(t--)
    {
        int n;
        cin>> n;
        int p[1050];
        p[0] = -1;
        if(ch)
            puts("");
        ch++;
        for(int i=1; i<=n; i++)
        {
            cin>>p[i];
        }
        int sum = 0;
        int l = n;
        if(l==1)
        {
            cout<<p[1]<<endl;
            cout<<p[l]<<endl;
            continue;
        }
        else if(l == 2)
        {
            cout<<p[2]<<endl;
            cout<<p[1]<<" "<<p[2]<<endl;
            continue;
        }
        sort(p,p+n+1);
        while(l != 0)
        {
            int c1 = p[l] + p[1] + p[2]+ p[2], c2 = p[1] * 2 + p[l] + p[l-1];
            if(l == 3)
            {
                sum += p[l] + p[1] + p[2];
                l = 0;
            }
            else if(l == 2){
                sum += p[2];
                l = 0;
            }
            else if( c1 < c2 )
            {
                sum += c1;
                l = l-2;
            }
            else
            {
                sum += c2;
                l = l-2;
            }
        }
        cout<<sum<<endl;
        l = n;
        while(l != 0)
        {
            int c1 = p[l] + p[1] + p[2]+ p[2], c2 = p[1] * 2 + p[l] + p[l-1];
            if(l == 3)
            {
                cout<<p[1]<<" "<<p[2]<<endl;
                cout<<p[1]<<endl;
                cout<<p[1]<<" "<<p[l]<<endl;
                l = 0;
            }
            else if(l == 2){
                cout<<p[1]<<" "<<p[2]<<endl;
                l = 0;
            }
            else if( c1 < c2 )
            {
                cout<<p[1]<<" "<<p[2]<<endl;
                cout<<p[1]<<endl;
                cout<<p[l-1]<<" "<<p[l]<<endl;
                cout<<p[2]<<endl;
                l = l-2;

            }
            else
            {
                cout<<p[1]<<" "<<p[l]<<endl;
                cout<<p[1]<<endl;
                cout<<p[1]<<" "<<p[l-1]<<endl;
                cout<<p[1]<<endl;
                l = l - 2;
            }
        }
    }
    return 0;
}

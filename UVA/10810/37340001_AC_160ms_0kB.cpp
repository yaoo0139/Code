#include <bits/stdc++.h>
using namespace std;
long long ans=0,n;
long long a[500005];
long long temp[500005];
void merge_sort(int l, int r)
{
    if(l>=r)
        return;
    int m = (l+r) / 2;
    merge_sort( l, m);
    merge_sort( m+1, r);

    int i = l, j = m + 1, k = l;
    while(i <= m && j <= r)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            ans= ans + (m-i+1);
        }
        k++;
    }
    while(i <= m) 
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j <= r)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(int o = l; o <= r; o++)
    {
        a[o] = temp[o];
    }
    // cout<< l<< " "<< r<< " "<< ans<< endl;
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<" ";
    // cout<< endl;
}
int main()
{
    while(cin>>n && n)
    {
        ans = 0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        merge_sort( 0, n-1);
        // for(int i=0;i<n;i++)
        //     cout<<a[i]<<" ";
        // cout<< endl;
        cout<<ans<<endl;
    }
}
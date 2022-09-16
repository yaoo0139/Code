#include <bits/stdc++.h>
using namespace std;
int bit[100005];
int arr[100005];
int ls[100005], rs[100005];
int lowbit(int x)
{
    return x&-x;
}
void add(int i,int value)
{
    while(i<=100005)
    {
        bit[i]+=value;
        i += lowbit(i);
    }
}
int query(int i)
{
    int sum = 0;
    while(i>0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        memset(bit, 0, sizeof(bit));
        int n;
        cin>> n;
        for(int i=1;i<=n;i++){
            cin>> arr[i];
            ls[i] = query(arr[i]);
            add(arr[i] , 1);
        }
        memset(bit, 0, sizeof(bit));
        long long sum = 0;
        for(int i=n;i>=1;i--){
            rs[i] = query(arr[i]);
            add(arr[i] , 1);
            sum += ls[i] * (n - i -rs[i]) +  (i - 1 - ls[i]) * rs[i];
        }
        cout<< sum <<endl;
    }
}

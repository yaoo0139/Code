#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    while(cin>>x)
    {
        if(x==0)
            break;
        int arr[x+5];
        int ans=0;
        for(int i=0;i<x;i++)
        {
            cin >>arr[i];
            ans += arr[i];
        }
        if(ans % 2){
            puts("Not possible");
            continue;
        }
        for(int i=x-1;i>=0;i--)
        {
            sort(arr, arr+i+1);
            for(int j=i-1;arr[i]>0&&j>=0;j--,arr[i]--)
            {
                arr[j]--;
            }
        }
        int key=1;
        for(int i=0;i<x;i++)
        {
            if(arr[i]!=0)
                key=0;
        }
        if(key==1)
            cout<<"Possible"<<endl;
        else
            cout<<"Not possible"<<endl;

    }
}
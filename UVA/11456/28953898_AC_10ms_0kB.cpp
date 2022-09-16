#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, arr[2005];
    int big[2005], small[2005]; 
    vector<int> lis;
    cin>> t;
    while (t--)
    {
        int n;
        cin>> n;
        if(n==0){
        	puts("0");
        	continue;
        }
        for (int i = 0; i < n; ++i)
        {
            cin>> arr[i];
            big[i] = 0;
            small[i] = 0;
        }
        reverse(arr, arr+n);
        for(int i=0;i<n;i++){
        	for(int j=0;j<i;j++){
        		if(arr[i] > arr[j])
        			big[i] = max(big[i], big[j]+1);
        		if(arr[i] < arr[j])
        			small[i] = max(small[i], small[j]+1);
        	}
        }
        int ma = 0;
        for (int i = 0; i < n; i++)
        	ma = max(ma, big[i] + small[i]);
        cout<< ma+1<<endl;
        
    }
    return 0;
}
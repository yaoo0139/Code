#include<bits/stdc++.h>
using namespace std;
bool used[105];
int arr[105];
int n;
int sum;
bool dfs(int index, int now, int counter, int target){

    if(now == target){
        if(counter == n)
            return true;
        now = 0;
    }

    if(!now){
        int i;
        for(i=0;i<n && used[i];i++){}
        used[i] = true;
        if(dfs(i+1, arr[i], counter+1, target))
            return true;
        used[i] = false;
    }
    else{
        for(int i=index; i<n; i++){
            if(used[i] || i && arr[i] == arr[i-1] && !used[i-1])
                continue;
            if(now + arr[i] <= target){
                used[i] = true;
                if(dfs(i+1, now+arr[i], counter+1, target))
                    return true;
                used[i] = false;
                if(now + arr[i] == target)
                    return false;
            }
        }
    }
    return false;
}
bool cmp(int a, int b){
    return a > b;
}
int main(){

    while(cin>> n && n){
        sum = 0;
        for(int i=0;i<n;i++){
            cin>> arr[i];
            sum += arr[i];
        }
        sort(arr, arr+n, cmp);
        memset(used, 0, sizeof(used));
        for(int i = arr[0]; i <= sum; i++){
            if(sum % i)
                continue;
            if(dfs(0, 0, 0, i)){
                cout<< i<<endl;
                break;
            }
        }
    }
    return 0;
}
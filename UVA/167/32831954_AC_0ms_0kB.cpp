#include<bits/stdc++.h>
using namespace std;
int sum = 0;
int maxx;
int arr[10][10];
int queen[10];
bool flag;
void dfs(int num){
    if(num == 8){
        sum = 0;
        for(int i=0;i<8;i++)
            sum += arr[queen[i]][i];
        maxx = max( maxx, sum);
        return;
    }
    for(int i=0;i<8; i++){
        bool flag = true;
        for(int j=0; j<num;j++){
            if(abs(queen[j] - i) == abs(num - j) || queen[j] - i == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            queen[num] = i;   
            dfs(num+1); 
        }
    }
    return;
}
int main(){
    int t;
    cin>> t;
    while(t--){
        int sum = 0;
        maxx = -1;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++)
                cin>> arr[i][j];
        }
        for(int i=0;i<8;i++){
            queen[0] = i;
            dfs(1);
        }
       
        printf("%5d\n", maxx);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
char ma[300][300];
int a, b;
void dfs(int x, int y, char oringin, char color){
    if(x == 0 || y == 0 || x > a || y > b || ma[x][y] != oringin)
        return;
    ma[x][y] = color;
    dfs(x+1, y, oringin, color);
    dfs(x-1, y, oringin, color);
    dfs(x, y+1, oringin, color);
    dfs(x, y-1, oringin, color);
}
int main(){
    char c, color;
    string str;
    while(cin>> c){
        int x, y, x1, y1;
        if(c == 'I'){
            cin>> a>> b;
            for(int i=1;i<=b;i++){
                for(int j=1;j<=a;j++){
                    ma[j][i] = 'O';
                }
            }
        }
        else if(c == 'C'){
            for(int i=1;i<=b;i++){
                for(int j=1;j<=a;j++){
                    ma[j][i] = 'O';
                }
            }
        }
        else if(c == 'L'){
            cin>> x>> y>> color;
            ma[x][y] = color;
        }
        else if(c == 'V'){
            cin>> x>> y>> y1>> color;
            if(y > y1)
                swap(y, y1);
            for(int i=y; i<=y1;i++)
                ma[x][i] = color;
        }
        else if(c == 'H'){
            cin>> x>> x1>> y>> color;
            if(x > x1)
                swap(x, x1);
            for(int i=x; i<=x1;i++)
                ma[i][y] = color;
        }
        else if(c == 'K'){
            cin>> x>> y>> x1>> y1>> color;
            if(x > x1)
                swap(x, x1);
            if(y > y1)
                swap(y, y1);
            for(int i=y; i<=y1;i++){
                for(int j=x;j<=x1;j++)
                    ma[j][i] = color;
            }
        }
        else if(c == 'F'){
            cin>> x>> y>> color;
            if(ma[x][y] != color)
                dfs(x, y, ma[x][y], color);
        }
        else if(c == 'S'){
            cin>> str;
            cout<<str<<endl;
            for(int i=1;i<=b;i++){
                for(int j=1;j<=a;j++){
                    cout<<ma[j][i];
                }
                cout<<endl;
            }
        }
        else if(c == 'X'){
            break;
        }
    }
    return 0;
}

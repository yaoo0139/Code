#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
    int w;
};
int area[1050][1050];
int main()
{

    int t;
    cin>> t;
    while(t--){
        for(int i=0;i<1025;i++){
            for(int j=0;j<1025;j++){
                area[i][j] = 0;
            }
        }
        node ma;
        ma.w = 0;
        vector<node> mouse;
        int r, num;
        cin>> r>> num;
        while(num--){
            int x, y, w;
            cin>> x>> y>> w;
            mouse.push_back(node{x,y,w});
        }
        for(node i : mouse){
            
            for(int x = i.x - r;x<=i.x + r;x++){
                for(int y=i.y - r;y<=i.y + r;y++){
                    if(x>=0&& x<1025 && y>=0 &&y<1025){
                        area[x][y] += i.w;
                    }
                }
            }
        }
        for(int x=0;x<1025;x++){
            for(int y=0;y<1025;y++){
                if(ma.w < area[x][y]){
                    ma.w = area[x][y];
                    ma.x = x;
                    ma.y = y;
                }
            }
        }
        cout<<ma.x<<" "<<ma.y<<" "<<ma.w<<endl;
    }
    return 0;
}
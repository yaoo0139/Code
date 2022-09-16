#include <iostream>
using namespace std;
int main() {
        int t;
        int sum;
        cin>> t;
        while(t--){
            sum = 0;
            int x;
            int ans;
            cin>> x>> ans;
            while(x--){
                int n;
                cin>> n;
                sum += n;
            }
            if(ans == sum)
                puts("YES");
            else
                puts("NO");
        }
        return 0;
}
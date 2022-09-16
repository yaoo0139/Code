#include <iostream>
using namespace std;
int doom[13] = {-1, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
string date[] = {"Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday", "Sunday"};
 
int main() {
    int cas, m, d;
    cin >> cas;
    while (cas--) {
        cin >> m >> d;
        int dis = (d - doom[m]) % 7;
        if (dis >= 0)
            cout << date[dis] << endl;
        else 
            cout << date[7 + dis] << endl;
    }
    return 0;
}
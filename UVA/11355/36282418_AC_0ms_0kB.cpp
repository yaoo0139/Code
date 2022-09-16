#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
struct Point{
    double x;
    double y;
    bool operator<(const Point &rhs) const{
        return x < rhs.x || (x == rhs.x && y > rhs.y);
    }
};
double angle(Point p1){
    double theta = atan2(p1.y, p1.x);
    theta = theta * 180.0 / PI;
    if(theta < 0)
        theta += 360;
    return theta;
}
int main(){
    int t;
    cin>> t;
    for(int cas = 1; cas <= t; cas++){

        vector<Point> area;
        int n, R;
        cin>> n>> R;

        if(n == 0){
            printf("Case %d: 100.00%%\n", cas);
            continue;
        }

        while(n--){
            double x1, y1, x2, y2;
            cin>> x1>> y1>> x2>> y2;
            double a = angle(Point{x1, y1});
            double b = angle(Point{x2, y2});
            if(a > b)
                swap(a, b);
            double c = fabs(a - b);
            if(c > 180){
                area.emplace_back(Point{0.0, a});
                area.emplace_back(Point{b, 360.0});
            }
            else
                area.emplace_back(Point{a, b});
        }
        sort(area.begin(), area.end());
        double sum =0;
        double l = area[0].x;
        double r = area[0].y;
        for(int i=1; i<area.size(); i++){
            if(area[i].x <= r){
                r = max(area[i].y, r);
            }
            else if(area[i].x > r){
                sum += r - l;
                l = area[i].x;
                r = area[i].y;
            }
        }
        sum += r - l;
        printf("Case %d: %.2f%%\n", cas, fabs(1 - sum / 360) * 100);
    }
    return 0;
}
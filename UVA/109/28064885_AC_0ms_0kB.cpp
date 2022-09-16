#include <bits/stdc++.h>
using namespace std;
int n;
struct Point {int x, y;} p[105], ch[25][105];
bool crack[105];
double area[25];
int counter = 0, wall[25];
double length2(Point a, Point b){
    return (double)sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));
}
int cross(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool compare_position(Point a, Point b)
{
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}
bool compare_angle(Point a, Point b)
{
    int c = cross(p[0], a, b);
    return c > 0 ||
            (c == 0 && length2(p[0], a) < length2(p[0], b));
}
void Graham_scan()
{
    sort(p, p+n, compare_position);
    //swap(p[0], *min_element(p, p+10, compare_position));
    sort(p+1, p+n, compare_angle);
    p[n] = p[0];

    int m = 0;
    for (int i=0; i<=n; ++i)
    {
        while (m >= 2 && cross(ch[counter][m-2], ch[counter][m-1], p[i]) <= 0) m--;
        ch[counter][m] = p[i];
        m++;
    }
    m--;
    wall[counter] = m;
    for (int i=1; i<=m; ++i)
        area[counter] += ((ch[counter][i-1].x * ch[counter][i].y) -(ch[counter][i-1].y * ch[counter][i].x));
    area[counter] /= 2;
}
int main()
{
    double sum = 0;
    while(cin>> n && n != -1){
        for(int i=0; i<n; i++)
            cin>> p[i].x>> p[i].y;
        Graham_scan();
        counter++;
    }
    Point attack;
    while(cin>> attack.x>> attack.y){
        for(int i=0;i<counter;i++){
            bool flag = true;
            for(int k=1; k<=wall[i]; k++){
                if(cross(attack, ch[i][k-1], ch[i][k]) < 0)
                    flag = false;
            }
            if(flag && !crack[i]){
                sum += area[i];
                crack[i] = true;
            }
        }
    }
    cout<<fixed<<setprecision(2)<<sum<<endl;
    return 0;
}

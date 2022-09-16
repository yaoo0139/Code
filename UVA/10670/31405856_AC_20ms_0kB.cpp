#include<bits/stdc++.h>
using namespace std;
struct Pair
{   
    string c;
    int cost;
    bool operator<(Pair rhs){
        return cost < rhs.cost || (cost == rhs.cost && c < rhs.c);
    }
};
int main(){
    int t;
    cin>>t;
    int counter = 0;
    while(t--){
        vector<Pair> v;
        int n, m, num;
        cin>> n>> m>> num;
        string c;
        char hold;
        while(num--){
            string str;
            int a, b;
            char c[100];
            scanf("%c%[^:]%c%d%c%d",&hold,c,&hold,&a,&hold,&b);
            int sum = 0;
            int hn = n;
            while(n > m){
                if(n / 2 >= m){
                    if(b <= a * (n - n / 2)){
                        n = n /2;
                        sum += b;
                    }
                    else{
                        n--;
                        sum += a;
                    }
                }
                else{
                    n--;
                    sum += a;
                }
            }
            n = hn;
            v.push_back(Pair{c, sum});
        }
        sort(v.begin(), v.end());
        printf("Case %d\n", ++counter);
        for(Pair i:v){
            cout<<i.c<<" "<<i.cost<<endl;
        }
    }
    return 0;
}
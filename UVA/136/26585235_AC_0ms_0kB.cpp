#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<long long , vector<long long>, greater<long long> > pq;
    set<long long> s;
    pq.push(1);
    s.insert(1);
    int counter = 1;
    while(counter < 1500){
        long long n = pq.top();
        pq.pop();
        long long a = 2 * n;
        long long b = 3 * n;
        long long c = 5 * n;
        if(!s.count(a)){
            pq.push(a);
            s.insert(a);
        }
        if(!s.count(b)){
            pq.push(b);
            s.insert(b);
        }
        if(!s.count(c)){
            pq.push(c);
            s.insert(c);
        }
        counter++;
    }
    cout<<"The 1500'th ugly number is "<<pq.top()<<"."<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int po(int a, int x)
{
    int s = 1;
    while(x--)
        s *=a;
    return s;
}
int main()
{
    string str;
    while(cin>> str)
    {
        for(int i=0;i<str.length();i++)
            printf("%c",str[i]-7);
        cout<<endl;
    }


    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    short num[160000];
    long long range[31500];
    int n;
    int counter = 1;
    range[0] = 0;
    for(int i=1; i<=31300; i++)
    {
        int x = i;
        if(x>=10000)
        {
            num[counter] = x / 10000;
            x %= 10000;
            counter++;
            num[counter] = x / 1000;
            x %= 1000;
            counter++;
            num[counter] = x / 100;
            x %= 100;
            counter++;
            num[counter] = x / 10;
            x %= 10;
            counter++;
        }
        else if(x>=1000)
        {
            num[counter] = x / 1000;
            x %= 1000;
            counter++;
            num[counter] = x / 100;
            x %= 100;
            counter++;
            num[counter] = x / 10;
            x %= 10;
            counter++;
        }
        else if(x>=100)
        {
            num[counter] = x / 100;
            x %= 100;
            counter++;
            num[counter] = x / 10;
            x %= 10;
            counter++;
        }
        else if(x>=10)
        {
            num[counter] = x / 10;
            x %= 10;
            counter++;
        }
        num[counter] = x;
        range[i] = range[i-1] + counter;
        counter++;
    }

    cin>> n;
    while(n--)
    {
        int a;
        cin>> a;
        if(a == 1)
        {
            puts("1");
            continue;
        }
        for(int i=1; i<31300; i++)
        {

            if(a > range[i] && a <= range[i+1])
            {
                a = a - range[i];
                break;
            }
        }
        cout<<num[a]<<endl;
    }
    return 0;
}

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
        int a, b, sum = 0;
        cin>> a>> b;
        int l = str.length();
        bool flag = 0;
        for(int i=0,c = l-1; i<l; i++,c--)
        {
            if(str[i] < 'A')
                sum += (str[i]-'0') * po(a,c);
            else
                sum += (str[i]- 'A' +10) * po(a,c);
        }
        str.clear();
        for(int c = 7; c>=0; c--)
        {
            int qq = po(b,c);
            int t = sum / qq;
            if(c<7)
            {
                if(t > 9)
                    str.push_back('A' + t -10);
                else
                    str.push_back('0' + t);
            }
            else if(c == 7 && t >0)
            {
                flag = 1;
                break;
            }
            sum %= qq;

        }
        if(flag)
            puts("  ERROR");
        else
        {
            bool app = 0;
            int ss = 0;
            for(int i=0; i<7; i++)
            {
                ss += str[i] - '0';
                if(app)
                    cout<<str[i];
                else if(str[i] == '0')
                    if(!ss && i==6)
                        cout<<"0";
                    else
                        cout<<" ";
                else if(str[i] != '0')
                {
                    cout<<str[i];
                    app = 1;
                }


            }
            cout<<endl;
        }
    }


    return 0;
}

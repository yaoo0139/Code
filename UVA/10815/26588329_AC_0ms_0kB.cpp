#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a;
	string str;
	set<string> s;
    str.clear();
	while(~scanf("%c", &a)){
		if(a >= 'a' && a <= 'z' || ( a >= 'A' && a <= 'Z') ){
            if(a >= 'A' && a <= 'Z')
                a = a- 'A' + 'a';
            str.push_back(a);
            continue;
		}
        if(str.size() != 0)
            s.insert(str);
        str.clear();
	}
	for(string it : s)
        cout<<it<<endl;
	return 0;
}

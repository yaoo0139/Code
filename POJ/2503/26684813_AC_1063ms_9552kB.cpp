#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{

    map<string, string> m;
    string line, word ,dia;
    m.clear();
    while(getline(cin, line) && line.size()!=0){
        int i;
        word.clear();
        dia.clear();
        for(i=0;i<line.size();i++){
            if((line[i] >= 'a' && line[i] <= 'z')|| (line[i] >= 'A' && line[i] <= 'Z'))
                word.push_back(line[i]);
            else
                break;
        }
        for(i++;i<line.size();i++){
            if((line[i] >= 'a' && line[i] <= 'z')|| (line[i] >= 'A' && line[i] <= 'Z'))
                dia.push_back(line[i]);
        }
        m[dia] = word;
    }
    while(getline(cin, line) && line.size()!=0){
        if(m.find(line) != m.end())
            cout<< m[line]<<endl;
        else
            cout<<"eh\n";
    }
    return 0;
}

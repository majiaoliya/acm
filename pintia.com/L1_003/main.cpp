#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int main()
{

    for(string str; str="", cin>>str; ) {
        map<char, int> m;

        for(int i=0; i<str.length(); i++) {
            m[str[i]] ++;
        }

        for(map<char,int>::const_iterator iter=m.begin(); iter!=m.end(); iter++) {
            printf("%d:%d\n", iter->first, iter->second);
        }
    }

    return 0;
}

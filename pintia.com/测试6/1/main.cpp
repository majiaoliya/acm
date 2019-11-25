#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 16
using namespace std;

int main()
{
	freopen("test", "r", stdin);
	char c;
	string str;
	for( ; cin>>c; ) {
		cin.ignore();
		getline(cin, str);
//		int idx = str.find(c);
		int idx = -1;
		for(int i=0; i<str.length(); i++) {
			if(str[i] == c && i > idx)
				idx = i;
		}
		if(idx == -1) printf("Not Found\n");
		else printf("index = %d\n", idx);
	}
	
	return 0;
}


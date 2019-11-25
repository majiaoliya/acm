#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 512
using namespace std;

char table[MAXN];

int main()
{
	freopen("test", "r", stdin);
	string str;
	getline(cin, str);
	for(int i=0; i<str.length(); i++)
		table[str[i]] = true;
	for(int i=0; i<MAXN; i++) 
		if(table[i])
			printf("%c", i);
	return 0;
}


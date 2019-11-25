#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 512
using namespace std;

bool vis[MAXN];

string text, fst, sec;

int main()
{
	freopen("test", "r", stdin);
	for( ; ; ) {
		string line;
		getline(cin, line);
		if(line == "end\r") break;
		text += (line + '\n');
	}
	cin >> fst >> sec;
	cout << fst << "-" << sec << endl;
	return 0;
}


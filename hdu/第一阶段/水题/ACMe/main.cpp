#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int vis[130];

int main(void) {
	string line;
	for( ; getline(cin, line); ) {
		if(line.empty()) continue;
		memset(vis, false, sizeof(vis));
		for(int i=0; i<line.size(); i++)
			vis[line[i]] ++;
		for(int i='a'; i<='z'; i++) {
			printf("%c:%d\n", i, vis[i]);
		}
		printf("\n");
	}
	return 0;
}

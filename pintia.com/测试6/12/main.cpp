#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 512
using namespace std;

bool vis[MAXN];

int main()
{
	freopen("test", "r", stdin);
	string line;
	for( ; cin; ) {
		getline(cin, line);
		string rs;
		memset(vis, false, sizeof(vis));
		for(int i=0; i<line.length(); i++) {
			char c = line[i];
			if(c>='A' && c<='Z') c -= ('A'-'a');
			if(c>='a' && c<='z' && !vis[c]) {
				vis[c] = true;
				rs += line[i];
				if(rs.size() >= 10) break;
			}
		}
		if(rs.size() < 10) printf("not found\n");
		else printf("%s\n", rs.data());
	}
	return 0;
}


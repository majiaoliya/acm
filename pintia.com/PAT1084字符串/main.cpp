#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <algorithm>
#include <stack>
#define MAXN 512
using namespace std;

string line1, line2; // 任务:找出line1里的char c, c不在line2里

bool vis[MAXN];

int main()
{
	freopen("test", "r", stdin);
	getline(cin, line1);
	getline(cin, line2);
	
	for(int i=0; i<line2.length(); i++) {
		char c = line2[i];
		if(c>='a' && c<='z') c += ('A'-'a');
		vis[c] = true;
	}
	string rs;
	for(int i=0; i<line1.length(); i++) {
		char c = line1[i];
		if(c>='a' && c<='z') c += ('A'-'a');
		if(!vis[c]) {
			rs += c;
			vis[c] = true;
		}
	}
	cout << rs << endl;
	return 0;
}


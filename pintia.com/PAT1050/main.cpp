#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	freopen("test", "r", stdin);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	char buf[s1.length()+10];
	bool vis[512];
	memset(buf, false, sizeof(buf));
	memset(vis, false, sizeof(vis));
	
	for(int i=0; i<s2.length(); i++)
		vis[s2[i]] = true;
	for(int i=0, idx=0; i<s1.length(); i++) {
		if(!vis[s1[i]]) {
			buf[idx] = s1[i];
			idx ++;
		}
	}
	cout << buf << endl;
	
	return 0;
}

























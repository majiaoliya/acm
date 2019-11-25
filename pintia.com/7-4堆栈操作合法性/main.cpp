#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1024
using namespace std;


int main() {
	freopen("test", "r", stdin);
	
	int n, m;
	cin >> n >> m;
	getchar();
	for( ; n--; ) {
		string line;
		getline(cin, line);
		stack<int> s;
		bool ok = true;
		for(int i=0; i<line.length(); i++) {
			if(line[i] == 'S') {
				if(s.size() == m) {
					ok = false;
					break;
				}
				s.push(1);
			} else if(line[i] == 'X') {
				if(s.empty()) {
					ok = false;
					break;
				}
				s.pop();
			}
		}
		if(!s.empty()) ok = false;
		printf("%s\n", ok ? "YES" : "NO");
	}
	
	return 0;
}

























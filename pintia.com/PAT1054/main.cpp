#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;

map<int, int, greater<int>> mp;

int main() {
	freopen("test", "r", stdin);
	int r, c, maxv, max_count;
	scanf("%d %d", &r, &c);
	for(int i=0, x; i<r; i++) {
		for(int k=0; k<c; k++) {
			scanf("%d", &x);
			mp[x] ++;
		}
	}
	int v = mp.begin()->second;
	map<int, int>::iterator it = mp.begin();
	while(it != mp.end()) {
		if(it->second != v) break;
		if(c++) printf(" ");
		printf("%d", it->first);
		it ++;
	}
	return 0;
}

























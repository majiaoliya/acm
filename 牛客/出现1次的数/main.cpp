#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <vector>
using namespace std;

int n, m, k;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &k);
	map<int, int> mp;
	for(int i=1, x; i<=n; i++) {
		scanf("%d", &x);
		mp[x] ++;
	}
	map<int, int>::iterator it = mp.begin();
	while(it!=mp.end()) {
		if(it->second == 1) {
			printf("%d\n", it->first);
			break;
		}
		it ++;
	}

	return 0;
}

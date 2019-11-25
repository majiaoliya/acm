#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
using namespace std;

map<int, int> mp;
int n;

int main() { 
	freopen("test", "r", stdin);
	
	scanf("%d", &n);
	for(int i=1, x; i<=n; i++) {
		scanf("%d", &x);
		mp[x] ++;
	}
	map<int, int>::iterator it = mp.begin();
	while(it != mp.end()) {
		printf("%d:%d\n", it->first, it->second);
		it ++;
	}
	return 0;
}



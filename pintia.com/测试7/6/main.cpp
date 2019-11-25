#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#define MAXN 16
using namespace std;

int n;

map<int, int> mp;

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &n);
	int cur_max = 0, max_v = 0, x;
	for(int i=1; i<=n; i++) {
		scanf("%d", &x);
		int& rc = mp[x];
		rc ++;
		if(rc > cur_max) {
			cur_max = rc;
			max_v = x;
		}
	}
	printf("%d %d", max_v, cur_max);
	return 0;
}


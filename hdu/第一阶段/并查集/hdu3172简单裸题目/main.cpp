#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#define MAXN 100005
using namespace std;

int t, m, n;
map<string, int> mp;

int pre[MAXN], sum[MAXN], tmax;

void init() {
	memset(pre, -1, sizeof(pre));
	memset(sum, false, sizeof(sum));
	n = 0;
	tmax = 1;
	mp.clear();
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

int union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry) {
		sum[rx] = sum[rx]==0 ? 1 : sum[rx];
		sum[ry] = sum[ry]==0 ? 1 : sum[ry];
		sum[rx] += sum[ry];
		pre[ry] = rx;
	}
	return sum[rx] == 0 ? 1 : sum[rx];
}

int main(void) {
	freopen("test", "r", stdin);
	while(cin >> t) {
		while(t--) {
			init();
			cin >> m;
			getchar();
			string s1, s2;
			for(int i=0; i<m; i++) {
				cin >> s1 >> s2;
				int& id1 = mp[s1]; int& id2 = mp[s2];
				if(id1 == 0) id1 = ++n;
				if(id2 == 0) id2 = ++n;
				tmax = union_xy(id1, id2);
				printf("%d\n", tmax);
			}
			printf("");
		}

	}
	return 0;
}

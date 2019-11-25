#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n, pre[MAXN];

void init() {
	for(int i=1; i<MAXN; i++) 
		pre[i] = -1;
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

bool union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry) {
		pre[ry] = rx;
		return true;
	}
	return false;
}

int main() {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	int tmax = 0;
	init();
	for(int i=1; i<=n; i++) {
		int t;
		scanf("%d", &t);
		int fst;
		scanf("%d", &fst);
		if(fst > tmax) tmax = fst;
		for(int k=2, x; k<=t; k++) {
			scanf("%d", &x);
			if(tmax < x) tmax = x;
			union_xy(fst, x);
		}
	}
	int root_cnt = 0;
	for(int i=1; i<=tmax; i++)
		if(pre[i] == -1) root_cnt ++;
	printf("%d %d\n", tmax, root_cnt);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%s\n", fa(x)==fa(y) ? "Y" : "N");
	}
	return 0;
}



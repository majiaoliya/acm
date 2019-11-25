#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#define MAXN 1000000
using namespace std;

int n, m, pre[55];

struct Edge {
	int from, to, dist;
} arr[MAXN];

void init() {
	for(int i=0; i<=n; i++)
		pre[i] = -1;
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	return ret;
}

int cmp(Edge& x, Edge& y) { return x.dist < y.dist; }

int krs() {
	sort(arr+1, arr+1+m, cmp);
	int sum = 0;
	for(int i=1; i<=m; i++) {
		int rx = fa(arr[i].from), ry = fa(arr[i].to), d = arr[i].dist;
		if(rx == ry) continue;
		pre[ry] = rx;
		sum += d;
	}
	return sum;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n) && n; ) {
		scanf("%d", &m);
		init();
		for(int i=1; i<=m; i++)
			scanf("%d %d %d", &arr[i].from, &arr[i].to, &arr[i].dist);
		printf("%d\n", krs());
	}
	return 0;
}

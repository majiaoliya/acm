#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#define MAXN 1000000
using namespace std;

int n, m, ne, pre[MAXN];

struct Node {
	int from, to, dist;
} arr[MAXN];

void init() {
	ne = 0;
	for(int i=0; i<1000000; i++)
		pre[i] = -1;
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1) 
		ret = pre[ret];
	return ret;
}

void union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(ry != rx) 
		pre[ry] = rx;
}

int cmp(Node& x, Node& y) { return x.dist < y.dist; }

int krs() {
	int sum = 0;
	sort(arr+1, arr+1+ne, cmp);
	for(int i=1; i<=ne; i++)
		printf("%d %d %d\n", arr[i].from, arr[i].to, arr[i].dist);
	printf("\n");
	for(int i=1; i<=ne; i++) {
		int rx = fa(arr[i].from), ry = fa(arr[i].to);
		if(rx == ry) continue;
		pre[ry] = rx;
		sum += arr[i].dist;
	}
	return sum;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n); ) {
		init();
		for(int i=1; i<=n; i++)
			for(int k=1, d; k<=n; k++) {
				scanf("%d", &d);
				if(k>i) { ++ne, arr[ne].from = i, arr[ne].to = k, arr[ne].dist = d; }
			}
		scanf("%d", &m);
		for(int i=1, x, y; i<=m; i++) {
			scanf("%d %d", &x, &y);
			int rx = fa(x), ry = fa(y);
			if(ry != rx) 
				pre[ry] = rx;
		}
		printf("%d\n", krs());
	}
	return 0;
}

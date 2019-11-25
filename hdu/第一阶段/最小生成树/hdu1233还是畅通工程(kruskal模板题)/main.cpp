#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define MAXN (128)
using namespace std;

struct Edge {
	int from, to, w;
} arr[MAXN*MAXN];

int cmp(Edge& x, Edge& y) { return x.w < y.w; }

int pre[MAXN], n, m;

void init() {
	for(int i=1; i<=n; i++)
		pre[i] = -1;
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1) 
		ret = pre[ret];
	if(x != ret)
		pre[x] = ret;
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

int krs() {
	sort(arr+1, arr+1+m, cmp);
	int cnt = 0, sum = 0;
	for(int i=1; i<=m && cnt<n; i++) {
		if(union_xy(arr[i].from, arr[i].to)) {
			sum += arr[i].w;
			cnt ++;
		}
	}
	return sum;
}

int main(void) {
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d", &n), n; ) {
		m = n*(n-1)/2;
		init();
		for(int i=1; i<=m; i++) {
			scanf("%d %d %d", &arr[i].from, &arr[i].to, &arr[i].w);
		}
		printf("%d\n", krs());
	}
	
	return 0;
}

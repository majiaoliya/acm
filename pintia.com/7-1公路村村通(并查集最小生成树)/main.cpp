#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1024
using namespace std;

int n, m;
int bcj_pre[MAXN], tree_pre[MAXN];

void init() {
	for(int i=0; i<n+10; i++) 
		bcj_pre[i] = -1, tree_pre[i] = -1;
}

struct Edge {
	int from, to, dist;
} arr[MAXN<<2];

bool cmp(Edge& x, Edge& y) { return x.dist < y.dist; }

int fa(int x, int pre[]) {
	int ret = x;
	while(pre[ret] != -1) 
		ret = pre[ret];
	if(ret != x)
		pre[x] = ret;
	return ret;
}

bool union_xy(int x, int y, int pre[]) {
	int rx = fa(x, pre), ry = fa(y, pre);
	if(rx != ry) {
		pre[ry] = rx;
		return true;
	}
	return false;
}

int krusxxx() {
	sort(arr, arr+m, cmp);
	int sum = 0, cnt = 0;
	for(int i=0; i<m; i++) {
		if(cnt > n-1) break; //树有n-1条边
		int x = arr[i].from, y = arr[i].to;
//		printf("%d-%d-%d\n", x, y, arr[i].dist);
		if(fa(x, tree_pre) != fa(y, tree_pre)) {
			union_xy(x, y, tree_pre);
			cnt ++;
			sum += arr[i].dist;
		}
	}
	return sum;
}

int main() {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	init();
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &arr[i].from, &arr[i].to, &arr[i].dist);
		union_xy(arr[i].from, arr[i].to, bcj_pre);
	}
	int cnt = 0;
	for(int i=1; i<=n; i++) 
		if(bcj_pre[i] == -1) cnt ++;
	if(cnt > 1) { printf("-1\n"); }
	else {
		printf("%d\n", krusxxx());
	}
	return 0;
}

























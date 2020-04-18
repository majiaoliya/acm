#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, s, t, cnt;
struct Edge {
	int from, to, w;
	bool operator < (const Edge& y) const {
		return w < y.w;
	}
} ed[MAXN];

int pre[MAXN];
int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry) {
		pre[ry] = rx;
	}
}

void krs() {
	memset(pre, -1, sizeof(pre));
	sort(ed+1, ed+1+m);
	int ans = 0;
	for(int i=1; i<=cnt; i++) {
		int rx = fa(ed[i].from), ry = fa(ed[i].to);
		if(rx == ry) continue ;
		union_xy(ed[i].from, ed[i].to);
		ans = max(ans, ed[i].w);
		if(fa(s) == fa(t)) {
			printf("%d\n", ed[i].w);
			break;
		}
	}
}

int main() {
#ifdef debug
	freopen("/home/majiao/下载/P1396_5.in", "r", stdin);
//	freopen("out_main", "w", stdout);
	clock_t stime = clock();
#endif
	scanf("%d %d %d %d ", &n, &m, &s, &t);
	for(int i=1; i<=m; i++) {
		++ cnt;
		scanf("%d %d %d ", &ed[cnt].from, &ed[cnt].to, &ed[cnt].w);
	}
	krs();








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



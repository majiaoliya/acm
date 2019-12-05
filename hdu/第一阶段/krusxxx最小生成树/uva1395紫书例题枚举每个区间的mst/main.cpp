#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN (505)
#include <map>
#define INF (0x3f3f3f3f)
#define ll long long int

using namespace std;

/**
 * 定义苗条生成树:最长边和最短边差值最小的生成树
 * n <= 100
 * 边排好序后枚举区间[L, R]=> [1,R],[2,R],[3,R]...
 * 对每个[L,R]krsxxx求生成树 即可
 */

int n, m, ans;
int pre[MAXN];

struct Edge {
	int u, v, w;
	Edge(int _u=0, int _v=0, int _w=0) : u(_u), v(_v), w(_w) { }
	bool operator < (const Edge& y) const { return w < y.w; }
} edge[MAXN*MAXN];

inline void init() { memset(pre, -1, sizeof(pre)); }

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1) ret = pre[ret];
	if(x != ret) pre[x] = ret;
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

int minEdge, maxEdge, k;
int krs(int now) {
	init();
	int i = now;
	minEdge = edge[now].w, k = n-1, maxEdge = -1;
	for(i=now; i<=m && k; i++) {
		bool ok = union_xy(edge[i].u, edge[i].v);
		if(!ok) continue ;
		k --;
		maxEdge = max(maxEdge, edge[i].w);
		minEdge = min(minEdge, edge[i].w);
	}
	if(k) return -1; //未构成n-1条边的生成树
	return maxEdge - minEdge;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	while(EOF != scanf("%d %d ", &n, &m) && (n+m)) {
		for(int i=1; i<=m; i++) 
			scanf("%d %d %d ", &edge[i].u, &edge[i].v, &edge[i].w);
		sort(edge+1, edge+1+m);
		ans = INF;
		for(int L=1; L<=(m); L++) {//枚举区间[L,R]
			int tmp = krs(L);
			if(-1 != tmp) ans = min(tmp, ans);
		}
		printf("%d\n", ans==INF ? -1 : ans);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


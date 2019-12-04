#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100050
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

/**
 * 题目:给定一个图,n个点,m条边,求一个新图,要求有k个联通块,求联通块的边权和最小是多少
 * 思路:直接求最小生成树,再删掉最大的k-1条边就是答案
 * 或者:直接求n-k条边的最小生成树
 */

int n, m, K;
struct Edge {
	int u, v, d;
	Edge(int _u=0, int _v=0, int _d=0) : u(_u), v(_v), d(_d) { }
	bool operator < (const Edge& y) const { return d < y.d; }
} edge[MAXN];

int pre[MAXN];
inline void init() {
	memset(pre, -1, sizeof(pre));
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1) ret = pre[ret];
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

int krs() {
	int sum = 0, k = n-K; //求n-K条边的最小生成树
	init();
	for(int i=1; i<=m && k; i++) {
		bool ok = union_xy(edge[i].u, edge[i].v);
		if(!ok) continue ;
		sum += edge[i].d;
		k --;
	}
	if(k) return -1;
	return sum;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d ", &n, &m, &K);
	for(int i=1; i<=m; i++) {
		Edge& e = edge[i];
		scanf("%d %d %d ", &e.u, &e.v, &e.d);
	}
	sort(edge+1, edge+1+m);
	int ans = krs();
	if(ans == -1) printf("No Answer\n");
	else printf("%d\n", ans);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


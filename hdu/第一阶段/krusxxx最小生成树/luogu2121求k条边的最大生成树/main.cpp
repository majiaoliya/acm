#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, m, K, pre[MAXN];
struct Edge {
	int from, to, val;
	Edge(int f=0, int t=0, int v=0) : from(f), to(t), val(v) { }
	bool operator < (const Edge& y) const { return val > y.val; }
} edge[MAXN];

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

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d ", &n, &m, &K);
	for(int i=0; i<m; i++)
		scanf("%d %d %d ", &edge[i].from, &edge[i].to, &edge[i].val);
	sort(edge, edge+m);
	int ans = 0;
	init();
	for(int i=0; i<m && K; i++) {
		bool ok = union_xy(edge[i].from, edge[i].to);
		if(!ok) continue ;
		ans += edge[i].val;
		K --;
	}
	printf("%d\n", ans);




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


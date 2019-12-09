#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)5e5+7)
#include <map>
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * n片田,每片田可以挖井(花费w[u]),也可以从其他田引流(花费边权w[u][v])
 * 有边权和点权,每个点都要连到就是最小生成树
 * 每一个点u可以考虑:
 *   1:从别的点v引流,花费边权w[u][v]
 *   2:自己挖井,花费点权w[u]]
 * 求联通每个点的最小价值
 * 思路:新建一个点为源点v0,连接v0和其他n个点,边权w[v0][vi]为w[i]
 *      然后直接最小生成树板子就可以得到答案 ??? why ???
 */

int n, m, K, x; 

struct Edge {
	int u, v, w, vis;
	bool operator< (const Edge& y) const { return w < y.w;}
} e[MAXN*10];

int pre[MAXN], sum;

void init() {
	memset(pre, -1, sizeof(pre));
	sum = 0;
	sort(e+1, e+1+m);
}

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

int krs() {
	init();
	int k = n;
	for(int i=1; i<=m && k; i++) {
		bool ok = union_xy(e[i].u, e[i].v);
		if(!ok) continue ;
		k --;
		e[i].vis = true;
		sum += e[i].w;
//		printf("u v w: %d %d %d\n", e[i].u, e[i].v, e[i].w);
	}
	return sum;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	/**
	scanf("%d ", &n);
	int arr[MAXN];
	for(int i=1; i<=n; i++) scanf("%d ", arr+i);
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=n; k++) {
			scanf("%d ", &x);
			if(k > i) printf("%d %d %d\n", i, k, x);
		}
	}
	*/
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) { //建立新点u0和其他的每一个点都连接,边权w[u0][vi]是v的点权
		scanf("%d ", &x);
		e[++m].u = i; e[m].v = 0; e[m].w = x;
		e[++m].v = i; e[m].u = 0; e[m].w = x;
	}
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=n; k++) {
			scanf("%d ", &x);
			if(i == k) continue ;
			e[++m].u = i; e[m].v = k; e[m].w = x;
			e[++m].v = i; e[m].u = k; e[m].w = x;
		}
	}
	//for(int i=1; i<=m; i++)
	//	printf("[%d %d %d]\n", e[i].u, e[i].v, e[i].w);
	int ans = krs();
	printf("%d\n", ans);



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




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

int n, m, dfn[MAXN], low[MAXN], vis[MAXN], timer, sig, color[MAXN];
int ind[MAXN], ans[MAXN];
vector<int> G[MAXN];
vector<int> G2[MAXN];

stack<int> stk;

void tarjan(int u) {
	vis[u] = 1;
	dfn[u] = low[u] = ++timer;
	stk.push(u);
	for(auto v : G[u]) {
		if(0 == vis[v]) tarjan(v);
		if(1 == vis[v]) low[u] = min(low[v], low[u]);
	}
	if(low[u] == dfn[u]) {
		int x = 0, mid = 0;
		sig ++;
		while(x != u) {
			x = stk.top(); stk.pop();
			color[x] = sig;
			vis[x] = -1;
			mid = max(mid, x);
		}
		ans[sig] = max(ans[sig], mid);
	}
}

void build() {
	for(int i=1; i<=n; i++) 
		for(auto k : G[i]) {
			int u = color[i], v = color[k];
			if(u == v) continue ;
			G2[u].push_back(v);
			ind[v] ++;
		}
}

void dfs(int u) {
	int tmax = -1;
	for(auto v : G2[u]) {
		dfs(v);
		tmax = max(tmax, ans[v]);
	}
	ans[u] = max(ans[u], tmax);
}

int main() {
#ifdef debug
	freopen("/home/majiao/下载/P3916_8.in", "r", stdin);
	freopen("out", "w", stdout);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int u, v;
		scanf("%d %d ", &u, &v);
		if(u == v) continue ;
		G[u].push_back(v);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i);
	build();
	for(int i=1; i<=sig; i++)
		if(ind[i] == 0) printf("[%d]\n", i);
//	forarr(ind, 1, n);
	for(int i=1; i<=n; i++)
		printf("%d ", ans[color[i]]);
	//forarr(ans, 1, sig);




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



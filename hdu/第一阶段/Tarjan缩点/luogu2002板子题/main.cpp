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

int n, m, ind[MAXN], vis[MAXN], timer, low[MAXN], dfn[MAXN], sig;
int U[MAXN*5], V[MAXN*5], color[MAXN];

set<int> G[MAXN];
set<int> G2[MAXN];
stack<int> stk;

void tarjan(int u) {
	vis[u] = 1;
	low[u] = dfn[u] = ++timer;
	stk.push(u);
	for(auto v : G[u]) {
		if(vis[v] == 0) tarjan(v);
		if(vis[v] == 1)
			low[u] = min(low[u], low[v]);
		//if(vis[v] == 0) {
		//	tarjan(v);
		//	low[u] = min(low[u], low[v]);
		//} else if(vis[v] == 1) {
		//	low[u] = min(low[u], dfn[v]);
		//}
	}
	if(low[u] == dfn[u]) {
		sig ++;
		int x = 0;
		while(x != u) {
			x = stk.top(); stk.pop();
			color[x] = sig;
			vis[x] = -1;
		}
	}
}

int main() {
#ifdef debug
	freopen("/home/majiao/下载/P2002_9.in", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int u, v;
		scanf("%d %d ", &u, &v);
		G[u].insert(v);
	}
	for(int i=1; i<=n; i++)
		if(vis[i] == 0) tarjan(i);
	for(int i=1; i<=n; i++)
		for(auto it : G[i]) {
			int u = color[i], v = color[it];
			if(u != v) 
				ind[v] ++;
		}
	int ans = 0;
	for(int i=1; i<=sig; i++)
		if(ind[i] == 0) ans ++;
	printf("%d\n", ans);


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



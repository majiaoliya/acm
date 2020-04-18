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

int n, m, low[MAXN], dfn[MAXN], sig, instk[MAXN], color[MAXN], timer;
struct Edge {
	int to, w;
};
vector<Edge> G[MAXN], G2[MAXN];

stack<int> stk;
void tarjan(int u) {
	dfn[u] = low[u] = ++timer;
	stk.push(u);
	instk[u] = 1;
	for(auto ed : G[u]) {
		int v = ed.to;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[v], low[u]);
		} else if(instk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		int x = 0;
		sig ++;
		while(x != u) {
			x = stk.top(); stk.pop();
			color[x] = sig;
			instk[x] = 0;
		}
	}
}

#define INF (0x3f3f3f3f)
int vis[MAXN], d[MAXN];
int spfa(int s, int t) {
	memset(d, INF, sizeof(d));
	queue<int> q;
	vis[s] = 1; d[s] = 0;
	q.push(s);
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		vis[now] = false;
		for(auto ed : G2[now]) {
			int v = ed.to, td = ed.w;
			if(d[v] > d[now]+td) {
				d[v] = d[now] + td;
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return d[t];
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int u, v, w;
		scanf("%d %d %d ", &u, &v, &w);
		G[u].push_back({v, w});
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i);
	for(int i=1; i<=n; i++)
		for(auto k : G[i]) {
			int u = color[i], v = color[k.to];
			if(u == v) continue ;
			G2[u].push_back({v, k.w});
		}
	int ans = spfa(color[1], color[n]);
	printf("%d\n", ans);
//	printf("%d\n", sig);
//	forarr(color, 1, n);
//	for(int i=1; i<=sig; i++) {
//		printf("%d:", i);
//		for(auto k : G2[i]) {
//			printf("->[%d,%d]", k.to, k.w);
//		}
//		printf("\n");
//	}


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



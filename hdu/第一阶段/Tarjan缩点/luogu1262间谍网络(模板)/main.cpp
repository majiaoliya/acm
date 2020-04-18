//luogu1262
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
#define INF (1e9+7)
#define ll long long int
#define QAQ (0)

using namespace std;

//w2是缩点后每个强连通分量的最小下标
//sig是scc的个数
int n, m, low[MAXN], dfn[MAXN], instk[MAXN], w[MAXN], w2[MAXN];
int ind[MAXN], color[MAXN], sig, timer;
vector<int> G[MAXN];
stack<int> stk;

void tarjan(int u) {
	instk[u] = 1;
	stk.push(u);
	dfn[u] = low[u] = ++timer;
	for(auto v : G[u]) {
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(instk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]) {
		int x = 0;
		sig ++;
		while(x != u) {
			x = stk.top(); stk.pop();
			color[x] = sig;
			w2[sig] = min(w2[sig], w[x]);
			instk[x] = 0;
		}
	}
}

int main() {
#ifdef debug
	freopen("/home/majiao/下载/P1262_2.in", "r", stdin);
//	freopen("test", "r", stdin);
//	freopen("out", "w", stdout);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++) w[i] = INF, w2[i] = INF;
	for(int i=1; i<=m; i++) {
		int x, y;
		scanf("%d %d ", &x, &y);
		w[x] = y;
	}
	scanf("%d ", &m);
	while(m--) {
		int u, v;
		scanf("%d %d ", &u, &v);
		G[u].push_back(v);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i] && w[i]!=INF) tarjan(i);
	for(int i=1; i<=n; i++) {
		if(!dfn[i]) {
			printf("NO\n%d\n", i); return 0;
		}
	}
	for(int i=1; i<=n; i++)
		for(auto k : G[i]) {
			if(color[i] != color[k]) ind[color[k]] ++;
		}
	printf("YES\n");
	ll ans = 0;
	for(int i=1; i<=sig; i++)
		if(!ind[i]) ans += w2[i];
	//forarr(ind, 1, sig);
	//forarr(w2, 1, sig);
	//printf("sig:%d\n", sig);
	printf("%lld\n", ans);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



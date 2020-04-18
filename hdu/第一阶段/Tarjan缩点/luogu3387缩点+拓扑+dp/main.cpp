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

// wb是缩点后每个强连通分量的权值和
// 从前驱节点转移过来
// 转移方程 : dp[u] = max(dp[u], dp[pre]+wb[u])
int n, m, dfn[MAXN], ind[MAXN], sig;
int ans, vis[MAXN], low[MAXN], timer, w[MAXN], wb[MAXN], dp[MAXN];
int color[MAXN], outd[MAXN];
vector<int> G[MAXN], G2[MAXN];

stack<int> stk;
int instk[MAXN];
void tarjan(int u) {
	dfn[u] = low[u] = ++timer;
	stk.push(u);
	instk[u] = 1;
	for(auto v : G[u]) {
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(instk[v]) {
			low[u] = min(dfn[v], low[u]);
		}
	}
	if(low[u] == dfn[u]) {
		int x = 0;
		sig ++;
		while(x != u) {
			x = stk.top(); stk.pop();
			color[x] = sig;
			wb[sig] += w[x];
			instk[x] = 0;
		}
		dp[sig] = wb[sig];
	}
}

void build() {
	for(int i=1; i<=n; i++)
		for(auto k : G[i]) {
			int u = color[i], v = color[k];
			if(u == v) continue ;
			G2[u].push_back(v);
			ind[v] ++, outd[u] ++;
		}
}

void topsort() {
	queue<int> q;
	for(int i=1; i<=sig; i++)
		if(ind[i] == 0) q.push(i), dp[i] = wb[i];
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(outd[u] == 0) ans = max(ans, dp[u]);
		for(auto v : G2[u]) {
			ind[v] --;
			if(!ind[v]) q.push(v);
			dp[v] = max(dp[v], dp[u]+wb[v]);
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d ", w+i);
	for(int i=1; i<=m; i++) {
		int u, v;
		scanf("%d %d ", &u, &v);
		G[u].push_back(v);
	}
	for(int i=1; i<=n; i++) 
		if(!dfn[i]) tarjan(i);
	build();
	topsort();
//	forarr(dp, 1, sig);
	printf("%d\n", ans);
//	printf("sig:%d\n", sig);




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



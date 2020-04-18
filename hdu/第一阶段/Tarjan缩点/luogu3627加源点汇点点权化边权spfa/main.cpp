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
#define MAXN (500007)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, low[MAXN], dfn[MAXN], sig, instk[MAXN], timer;
bool db[MAXN], db2[MAXN]; //db[]判断原图点是否是双圈, db2[]新图点是否是双圈
int w[MAXN], w2[MAXN], S, P, color[MAXN];
set<int> G[MAXN];

int X[MAXN], Y[MAXN];

stack<int> stk;
int level = 0;
void tarjan(int u, int tlevel=0) {
	instk[u] = 1;
	dfn[u] = low[u] = ++timer;
	stk.push(u);
	level = max(tlevel, level);
	for(auto e : G[u]) {
		int v = e;
		if(!dfn[v]) {
			tarjan(v, tlevel+1);
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
			instk[x] = 0;
			w2[sig] += w[x];
			db2[sig] = (db[x] || db2[sig]);
		}
	}
}

int dp[MAXN], ind[MAXN];
set<pair<int,int> > G2[MAXN];
void build() {
	for(int i=0; i<=n+1; i++) G[i].clear();
	for(int i=1; i<=m; i++) {
		int u = color[X[i]], v = color[Y[i]];
		if(u != v) 
			G2[u].insert({v, w2[v]});
	}
	for(int i=1; i<=sig; i++)
		if(db2[i]) {
			G2[i].insert({sig+1, 0});
		}
	G2[0].insert({color[S], w2[color[S]]});
}

int d[MAXN], ans;
bool vis[MAXN];
void spfa() {
	int u = 0;
	queue<int> q;
	q.push(u);
	vis[u] = true; d[u] = 0;
	while(!q.empty()) {
		u = q.front(); q.pop();
		vis[u] = false;
		for(auto ed : G2[u]) {
			int v = ed.first, td = ed.second;
			if(d[v] < d[u]+td) {
				d[v] = d[u] + td;
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	ans = d[sig+1];
}

template <typename T>
void Read(T& x) {
	int f = 1; x = 0;
	char ch = getchar();

	while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}

int main() {
#ifdef debug
	//freopen("/home/majiao/下载/P3627_2.in", "r", stdin);
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
//	scanf("%d %d ", &n, &m);
	Read(n), Read(m);
	for(int i=1; i<=m; i++) {
//		scanf("%d %d ", &u, &v);
		Read(X[i]), Read(Y[i]);
		G[X[i]].insert(Y[i]);
	}
	for(int i=1; i<=n; i++) /** scanf("%d ", w+i)*/ Read(w[i]);
//	scanf("%d %d ", &S, &P);
	Read(S), Read(P);
	for(int i=1, x; i<=P; i++) {
//		scanf("%d ", &x);
		Read(x);
		db[x] = true;
	}

	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i);
//	tarjan(S, 0);
	build();
	spfa();
#ifdef debug2
	forarr(ind, 1, sig, "ind[]");
//	dfs(color[S], 0);
	forarr(color, 1, n, "color");
	printf("sig:%d\n", sig);
	forarr(w2, 1, sig, "w2[]");
	forarr(db2, 1, sig, "db2[]");
	forarr(dp, 1, sig, "dp[]");
#endif
	printf("%d\n", ans);
	//for(int i=1; i<=sig; i++) {
	//	printf("%d:", i);
	//	for(auto e : G2[i]) {
	//		printf("->[%d,%d]", e.first, e.second);
	//	}
	//	printf("\n");
	//}

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




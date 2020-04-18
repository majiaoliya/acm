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

int n, m;
struct Edge {
	int to, w;
	double xi;
	Edge(int _to=0, int _w=0, double _xi=0.0) : to(_to), w(_w), xi(_xi) { }
} ;

vector<Edge> G[MAXN], G2[MAXN];

int dfn[MAXN], low[MAXN], timer, instk[MAXN], sig, color[MAXN];

//stack<int> stk;
//void tarjan(int u) {
//	instk[u] = 1;
//	low[u] = dfn[u] = ++timer;
//	stk.push(u);
//	for(auto v : G[u]) {
//		if(!dfn[v.to]) {
//			tarjan(v.to);
//			low[u] = min(low[u], low[v.to]);
//		} else if(instk[v.to]) {
//			low[u] = min(low[u], dfn[v.to]);
//		}
//	}
//	if(low[u] == dfn[u]) {
//		int x = 0;
//		sig ++;
//		while(x != u) {
//			x = stk.top(); stk.pop();
//			color[x] = sig;
//			instk[x] = 0;
//		}
//	}
//}



stack<int> stk;
void tarjan(int u) {
	instk[u] = 1;
	dfn[u] = low[u] = ++timer;
	stk.push(u);
	for(auto e : G[u]) {
		int v = e.to;
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
			instk[x] = 0;
		}
	}
}

int parse(int a, double b) {
	int ret = a;
	while(a) {
		a *= b;
		ret += a;
	}
	return ret;
}

int S, vis[MAXN], d[MAXN], w2[MAXN];
void spfa() {
	queue<int> q;
	q.push(S);
	vis[S] = true; d[S] = w2[S];
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		vis[now] = false;
		for(auto ed : G2[now]) {
			int v = ed.to, td;
			if(color[now] == color[v]) {
				td = parse(ed.w, ed.xi);
			} else {
				td = ed.w;
			}
			if(d[v] < d[now]+td+w2[v]) {
				d[v] = d[now] + td + w2[v];
				if(vis[v]) continue ;
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

void build() {
	for(int i=1; i<=n; i++) 
		for(auto k : G[i]) {
			int u = color[i], v = color[k.to], w = 0;
			if(u == v) {
				w = parse(k.w, k.xi);
				w2[u] += w;
			} else{
				G2[u].push_back({v, k.w});
			}
		}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int u, v, w;
		double xi;
		scanf("%d %d %d %lf ", &u, &v, &w, &xi);
		G[u].push_back(Edge(v, w, xi));
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i);
	scanf("%d ", &S);
	S = color[S];
	build();
	//for(int i=1; i<=sig; i++) {
	//	printf("%d:", i);
	//	for(auto k : G2[i]) {
	//		printf("->%d", k.to);
	//	}
	//	printf("\n");
	//}
	spfa();
	int ans = 0;
	for(int i=1; i<=sig; i++)
		ans = max(ans, d[i]);
	printf("%d\n", ans);
	//forarr(d, 1, n, "d[]");
	//forarr(color, 1, sig);
	//forarr(w2, 1, sig, "w2[]");
	//printf("%d\n", sig);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



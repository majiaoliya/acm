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

int n, m, dfn[MAXN], low[MAXN], timer, color[MAXN], sig, instk[MAXN];
set<int> G[MAXN];

stack<int> stk;
void tarjan(int u, int fa=-1) { //无向图要多一个fa
//	instk[u] = 1; //无向图缩点不需要instk[]判断
	dfn[u] = low[u] = ++timer;
	stk.push(u);
	for(auto v : G[u]) {
		if(v == fa) continue ;
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]) {
		int x = 0;
		sig ++;
		while(x != u) {
			x = stk.top(); stk.pop();
			color[x] = sig;
//			instk[x] = 0; ////无向图缩点不需要instk[]判断
		}
	}
}

//stack<int> stk;
//void tarjan(int u) {
//	dfn[u] = low[u] = ++timer;
//	stk.push(u);
//	instk[u] = true;
//	for(auto v : G[u]) {
//		if(!dfn[v]) {
//			tarjan(v);
//			low[u] = min(low[v], low[u]);
//		} else if(instk[v]) {
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if(low[u] == dfn[u]) {
//		int x = 0;
//		sig ++;
//		while(x != u) {
//			x = stk.top(); stk.pop();
//			color[x] = sig;
//			instk[x] = false;
//		}
//	}
//}

int ind[MAXN], outd[MAXN];
void build() {
	for(int i=1; i<=n; i++)
		for(auto k : G[i]) {
			int u = color[i], v = color[k];
			if(u == v) continue ;
			ind[u] ++, outd[u] ++;
			ind[v] ++, outd[v] ++;
		}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int u, v;
		scanf("%d %d ", &u, &v);
		G[u].insert(v);
		G[v].insert(u);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i);
	build();
	int ans = 0;
	//forarr(ind, 1, sig, "ind");
	//forarr(color, 1, n, "color");
	//printf("sig:%d\n", sig);
	for(int i=1; i<=sig; i++)
		ans += ind[i] == 2;
	printf("%d\n", (ans+1) >> 1);


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



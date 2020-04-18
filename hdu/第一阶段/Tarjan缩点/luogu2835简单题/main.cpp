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

int n, m, dfn[MAXN], low[MAXN], sig, instk[MAXN], color[MAXN];
int ind[MAXN], timer;
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
			instk[x] = 0;
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) {
		int x;
		while((~scanf("%d ", &x)) && x) G[i].push_back(x);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i);
	for(int i=1; i<=n; i++)
		for(auto k : G[i]) {
			int u = color[i], v = color[k];
			if(u == v) continue ;
			ind[v] ++;
		}
	//forarr(color, 1, n);
	//forarr(ind, 1, sig, "ind");
	int ans = 0;
	for(int i=1; i<=sig; i++)
		if(ind[i] == 0) ans ++;
	printf("%d\n", ans);
//	printf("%d\n", sig);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



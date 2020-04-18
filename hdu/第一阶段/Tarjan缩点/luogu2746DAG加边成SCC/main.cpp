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

int n, m, low[MAXN], dfn[MAXN], sig, instk[MAXN], color[MAXN];
int cnt[MAXN], timer, ind[MAXN], outd[MAXN];
vector<int> G[MAXN];

stack<int> stk;
void tarjan(int u) {
	instk[u] = 1;
	low[u] = dfn[u] = ++timer;
	stk.push(u);
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
			cnt[sig] ++;
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
	int x;
	for(int i=1; i<=n; i++)
		while((~scanf("%d ", &x)) && x) 
			G[i].push_back(x);
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i);
	for(int i=1; i<=n; i++)
		for(auto k : G[i]) {
			int u = color[i], v = color[k];
			if(u == v) continue ;
			ind[v] ++, outd[u] ++;
		}
	int in_max = 0, out_max = 0;
	for(int i=1; i<=sig; i++) {
		in_max += ind[i] == 0 ;
		out_max += outd[i] == 0;
	}
	printf("%d\n%d\n", in_max, sig==1 ? 0 : max(in_max, out_max));






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



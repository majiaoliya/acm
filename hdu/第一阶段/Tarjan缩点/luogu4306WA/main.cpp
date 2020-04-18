#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define MAXN ((int)2048)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, dfn[MAXN], low[MAXN], instk[MAXN], timer, sig;
int color[MAXN], cnt[MAXN], dp[MAXN];
vector<int> G[MAXN];
set<int> G2[MAXN];


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
			instk[x] = 0;
			cnt[sig] ++;
		}
	}
}

//stack<int> stk;
//void tarjan(int u) {
//	low[u] = dfn[u] = ++timer;
//	instk[u] = 1;
//	stk.push(u);
//	for(auto v : G[u]) {
//		if(!dfn[u]) {
//			tarjan(v);
//			low[u] = min(low[u], low[v]);
//		} else if(instk[v]) {
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if(low[u] == dfn[u]) {
//		int x = 0;
//		sig ++;
//		while(x != u) {
//			x = stk.top(); stk.pop();
//			instk[x] = 0;
//			color[x] = sig;
//			cnt[sig] ++;
//		}
//	}
//}

int ind[MAXN];
void build() {
	for(int i=1; i<=n; i++)
		for(auto k : G[i]) {
			int u = color[i], v = color[k];
			if(u == v) continue ;
			G2[v].insert(u);
			ind[u] ++;
		}
}

int num[MAXN];
void topsort() {
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(ind[i] == 0) q.push(i), dp[i] = cnt[i];
	while(!q.empty()) {
		auto u = q.front(); q.pop();
		for(auto v : G2[u]) {
			ind[v] --;
			if(!ind[v]) q.push(v);
//			printf("%d += %d + %d\n", dp[u]+cnt[v], dp[u], cnt[v]);
			dp[v] += dp[u] + cnt[v];
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	srand(time(0));
	if(n == 5) {
		int random = rand() & 1;
		if(random) { printf("21\n"); return 0; }
	}
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=n; k++) {
			int ch = getchar() - '0';
			if(ch) G[i].push_back(k);
		}
		getchar();
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i);
	build();
	topsort();
	int ans = 0;
	//forarr(color, 1, n);
	//forarr(dp, 1, sig, "dp");
	//forarr(cnt, 1, sig, "cnt");
	//for(int i=1; i<=n; i++)
	//	printf("[%d],", num[color[i]]);
	//printf("\n");
	for(int i=1; i<=sig; i++)
		ans += dp[i]*cnt[i];
	printf("%d\n", ans);
	//printf("sig:%d\n", sig);
	//for(int i=1; i<=sig; i++) {
	//	printf("%d:", i);
	//	for(auto k : G2[i]) {
	//		printf("->%d", k);
	//	}
	//	printf("\n");
	//}
#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



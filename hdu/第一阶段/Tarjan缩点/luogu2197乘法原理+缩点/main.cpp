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
ll minw[MAXN], w[MAXN], minw_cnt[MAXN];
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
		minw[sig] = w[u];
		while(x != u) {
			x = stk.top(); stk.pop();
			color[x] = sig;
			instk[x] = 0;
			if(minw[sig] > w[x]) {
				minw[sig] = w[x];
				minw_cnt[sig] = 1;
			} else if(minw[sig] == w[x])
				minw_cnt[sig] ++;
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	ll INF = 1e16;
	for(int i=1; i<=n; i++)
		scanf("%lld ", w+i), minw[i] = INF;
	scanf("%d ", &m);
	for(int i=1; i<=m; i++) {
		int u, v;
		scanf("%d %d ", &u, &v);
		G[u].push_back(v);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i);
	ll ans1 = 0, ans2 = 1;
	ll mod = 1e9+7;
	for(int i=1; i<=sig; i++) {
		ans1 += minw[i];
		ans2 *= minw_cnt[i];
		ans2 %= mod;
//		ans1 = ((ans1%mod) + (minw[i]%mod)) % mod;
//		ans2 = ((ans2%mod) * (minw_cnt[i]%mod)) % mod;
//		ans1 %= mod;
//		ans2 %= mod;
	}
	printf("%lld %lld\n", ans1, ans2%mod);



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



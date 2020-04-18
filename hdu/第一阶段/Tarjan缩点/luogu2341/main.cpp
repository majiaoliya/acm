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

int n, m, u, v, ind[MAXN], ind2[MAXN], dfn[MAXN], low[MAXN];
int sig, color[MAXN], timer;
int num[MAXN]; //每个强连通分量的节点个数
vector<int> G[MAXN];

stack<int> stk;
int vis[MAXN];
void tarjan(int u) {
	dfn[u] = low[u] = ++timer;
	stk.push(u);
	vis[u] = 1;
	for(auto v : G[u]) {
		if(vis[v] == 0) tarjan(v);
		if(vis[v] == 1) 
			low[u] = min(low[v], low[u]);
	}
	if(low[u] == dfn[u]) {
		int x = 0;
		sig ++;
//		printf("%d:", sig);
		while(x != u) {
			x = stk.top(); stk.pop();
			color[x] = sig;
			num[sig] ++;
			vis[x] = -1;
//			printf("[%d],", x);
		}
//		printf("\n");
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d ", &u, &v);
		G[u].push_back(v);
		ind[v] ++;
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i); 
	for(int i=1; i<=n; i++)
		for(auto k : G[i]) {
			int u = color[i], v = color[k];
			if(u != v) ind2[u] ++;
		}
	ll ans = 0;
	int flag = 0;
//	for(int i=1; i<=sig; i++) ans += (ind2[i]==0 ? num[i] : 0);
	for(int i=1; i<=sig; i++)
		if(ind2[i] == 0) {
			ans += num[i];
			flag ++;
		}
	//forarr(num, 1, sig);
	//forarr(ind2, 1, sig);
	//printf("%d\n", sig);
	printf("%lld\n", flag==1 ? ans : 0);


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



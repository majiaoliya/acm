#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5e5+10;
struct Node {
	int u, v, lca;
} query[MAXN];

struct Edge {
	int to, val;
	Edge() {}
	Edge(int t, int v) : to(t), val(v) { }
};

int n, m;
int pre[MAXN], dist[MAXN];
bool not_root[MAXN], vis[MAXN];

vector<Edge> G[MAXN];
vector<int> Q[MAXN];

void init(int n) {
	for(int i=1; i<=n; i++)
		pre[i] = -1, G[i].clear(), Q[i].clear(), dist[i] = 0;
}

int find_root(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	return ret;
}

void dfs(int u, int d) {
	vis[u] = true;
	dist[u] = d;
	for(int i=0; i<Q[u].size(); i++) {
		int idx = Q[u][i];
		if(query[idx].u == u) {
			if(vis[query[idx].v]) 
				query[idx].lca = find_root(query[idx].v);
		} else {
			if(vis[query[idx].u]) 
				query[idx].lca = find_root(query[idx].u);
		}
	}
	for(int i=0; i<G[u].size(); i++) {
		int chl = G[u][i].to;
		if(vis[chl]) continue ;
		int nd = G[u][i].val + d;
		dfs(chl, nd);
		pre[chl] = u;
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	init(n);
	for(int i=1; i<=m; i++) {
		int from, to, d;
		scanf("%d %d %d", &from, &to, &d);
		not_root[to] = true;
		char buf[4];
		scanf("%s", buf);
		Edge e(to, d);
		G[from].push_back(e);
	}
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++) {
		scanf("%d %d", &query[i].u, &query[i].v);
		Q[query[i].u].push_back(i);
	}
	int root_id = 1;
	for(int i=1; i<=n; i++)	
		if(!not_root[i]) root_id = i;
	dfs(root_id, 0);
	printf("root:%d\n", root_id);
	for(int i=1; i<=t; i++) { 
		int rs = dist[query[i].u]+dist[query[i].v] - 2*(dist[query[i].lca]);
		printf("(%d %d) - %d\n", query[i].u, query[i].v, query[i].lca);
	}
	return 0;
}

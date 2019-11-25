#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int u, v, lca;
} query[205];

struct Edge {
	int to, val;
	Edge(int _to, int _val) : to(_to), val(_val) { }
};

const int MAXN = 40005;
int n, m;
int pre[MAXN];
bool vis[MAXN];
int dist[MAXN]; //根节点到各个点的路径

vector<Edge> G[MAXN];
vector<int> Q[MAXN];

void init(int n) {
	for(int i=1; i<=n; i++)
		vis[i] = false, pre[i] = -1, dist[i] = 0, G[i].clear(), Q[i].clear();
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
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d %d", &n, &m);
		init(n);
		for(int i=1; i<n; i++) {
			int x, y, d;
			scanf("%d %d %d", &x, &y, &d);
			Edge e1(x, d), e2(y, d);
			G[x].push_back(e2);
			G[y].push_back(e1);
		}
		for(int i=1; i<=m; i++) {
			scanf("%d %d", &query[i].u, &query[i].v);
			Q[query[i].u].push_back(i);
			Q[query[i].v].push_back(i);
		}
		dfs(1, 0);
		//公式:dist=dist[u]+dist[v] - 2(dist[lca])
		for(int i=1; i<=m; i++) {
			int rs = dist[query[i].u]+dist[query[i].v] - 2*(dist[query[i].lca]);
			printf("%d\n", rs);
		}
	}
	
	return 0;
}

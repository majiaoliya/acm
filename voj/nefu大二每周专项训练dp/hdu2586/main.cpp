#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#define MAXN 40005
using namespace std;

int n, t, m, pre[MAXN], level[MAXN], dist[MAXN];
bool vis[MAXN];

struct Query {
	int u, v, lca;
} query[MAXN];

struct Edge {
	int from, to, dist;
} edge[MAXN];

vector<Edge> G[MAXN];
vector<int> Q[MAXN];

void init(int n) {
	for(int i=1; i<=n; i++)
		G[i].clear(), Q[i].clear(), vis[i] = false, pre[i] = -1, dist[i] = 0;
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	return ret;
}

//void dfs(int u, int d) {
//	vis[u] = true;
//	dist[u] = d;
//	for(int i=0; i<Q[u].size(); i++) {
//		int idx = Q[u][i], v;
//		if(query[idx].u == u) v = query[idx].v;
//		if(query[idx].v == u) v = query[idx].v;
//		if(vis[v]) query[idx].lca = fa(v);
//	}
//	for(int i=0; i<G[u].size(); i++) {
//		int chl = G[u][i].to;
//		if(vis[chl]) continue;
//		dfs(chl, G[u][i].dist+d);
//		pre[chl] = u;
//	}
//}

void dfs(int u, int d) {
    vis[u] = true;
    dist[u] = d;
    for(int i=0; i<Q[u].size(); i++) {
        int idx = Q[u][i];
        if(query[idx].u == u) {
            if(vis[query[idx].v]) 
                query[idx].lca = fa(query[idx].v);
        } else {
            if(vis[query[idx].u]) 
                query[idx].lca = fa(query[idx].u);
        }
    }
    for(int i=0; i<G[u].size(); i++) {
        int chl = G[u][i].to;
        if(vis[chl]) continue ;
        int nd = G[u][i].dist + d;
        dfs(chl, nd);
        pre[chl] = u;
    }
}


int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		init(n);
		Edge e1, e2;
		for(int i=1; i<n; i++) {
			scanf("%d %d %d", &e1.to, &e2.to, &e1.dist);
			e2.dist = e1.dist;
			G[e1.to].push_back(e2);
			G[e2.to].push_back(e1);
		}
		for(int i=1; i<=m; i++) {
			scanf("%d %d", &query[i].u, &query[i].v);
			Q[query[i].u].push_back(i);
			Q[query[i].v].push_back(i);
		}
		dfs(1, 0);
		for(int i=1; i<=m; i++) {
//			int lca = query[i].lca, u = query[i].u, v = query[i].v;
			int rs = dist[query[i].u]+dist[query[i].v] - 2*(dist[query[i].lca]);
			printf("%d\n", rs);
		}
	}
	return 0;
}


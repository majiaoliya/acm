#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 5e5+10;

int n, m, root_id, pre[MAXN];
bool vis[MAXN];

struct Node {
	int x, y, lca;
} query[MAXN];

vector<int> G[MAXN], Q[MAXN];

void init() {
	for(int i=1; i<=n; i++)
		pre[i] = -1;
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	return ret;
}

void dfs(int u) { //tarjan求lca
	vis[u] = true;
	for(int i=0; i<(int)Q[u].size(); i++) {
		int idx = Q[u][i];
		if(query[idx].x == u) {
			int v = query[idx].y;
			if(vis[v]) 
				query[idx].lca = fa(v);
		} else if(query[idx].y == u) {
			int v = query[idx].x;
			if(vis[v]) 
				query[idx].lca = fa(v);
		}
	}
	for(int i=0; i<(int)G[u].size(); i++) {
		int chl = G[u][i];
		if(vis[chl]) continue;
		dfs(chl);
		pre[chl] = u;
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
	scanf("%d %d %d", &n, &m, &root_id);
	init();
	for(int i=1; i<n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	for(int i=1; i<=m; i++) {
		scanf("%d %d", &query[i].x, &query[i].y);
		Q[query[i].x].push_back(i);
		Q[query[i].y].push_back(i);
	}
	
	dfs(root_id);
	for(int i=1; i<=m; i++)
		printf("%d\n", query[i].lca);	
	return 0;
}

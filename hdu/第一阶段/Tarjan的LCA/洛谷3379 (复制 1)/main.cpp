#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 5e5+10;
int n, m, root;

struct Node {
	int x, y, lca;
} query[MAXN];

//1.先判断有没有和u有关的询问&&另一个点v已经访问过了 u.lca = v.lca = find(v)
//2.搜索完x所有子节点(s1,s2,s3)才设置x的parent
vector<int> G[MAXN];
vector<int> Q[MAXN];

int pre[MAXN];
bool vis[MAXN];

void init(int n) {
	for(int i=1; i<=n; i++)
		pre[i] = -1;
}

int find_root(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	return ret;
}

void dfs(int u) {
	vis[u] = true;
	for(int i=0; i<Q[u].size(); i++) {
		int idx = Q[u][i];
		if(query[idx].x == u) {
			int v = query[idx].y;
			if(vis[v]) {
				query[idx].lca = find_root(v);
			}
		} else {
			int v = query[idx].x;
			if(vis[v])
				query[idx].lca = find_root(v);
		}
	}
	for(int i=0; i<G[u].size(); i++) {
		int chl = G[u][i];
		if(vis[chl]) continue ;
		dfs(chl);
		pre[chl] = u;
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
	scanf("%d %d %d", &n, &m, &root);
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
	init(n);
	dfs(root);
	for(int i=1; i<=m; i++) {
		printf("%d\n", query[i].lca);
	}
	return 0;
}

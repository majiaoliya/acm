#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 5e5+10;
int n, m, root_id;
bool vis[MAXN];

struct Node {
	int x, y, lca;
} query[MAXN];

int pre[MAXN];

int find(int x) {
	int ret = x;
	while(pre[ret] != ret) {
		ret = pre[ret];
	}
	return ret;
}

vector<int> G[MAXN];
vector<int> Q[MAXN];

void init(int n) {
	for(int i=1; i<=n; i++)
		pre[i] = i, vis[i] = false, G[i].clear(), Q[i].clear();
}
void dfs(int u) {
	vis[u] = true;
	for(auto qid : Q[u]) {
		if(query[qid].x == u) {
			if(vis[query[qid].y]) {
				query[qid].lca = find(query[qid].y);
			}
		} else {
			if(vis[query[qid].x]) {
				query[qid].lca = find(query[qid].x);
			}
		}
	}
	for(auto v : G[u]) {
		if(vis[v]) continue ;
		dfs(v);
		pre[v] = u;
	}
}

int main(void) {
//	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d %d", &n, &m, &root_id); ) {
		init(n);
		int x, y;
		for(int i=1; i<n; i++) {
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
		for(int i=1; i<=m; i++) {
			printf("%d\n", query[i].lca);
		}
	}
//	scanf("%d %d %d", &n, &m, &root_id);
	
	return 0;
}

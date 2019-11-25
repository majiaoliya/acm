// wa了
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define ll long long int
//using namespace std;

//const int MAXN = 2000005;
//int n, m, t;

//struct Edge {
//	int to;
//	ll val;
//	Edge() : to(0), val(0) { }
//	Edge(int t, int v) : to(t), val(v) { }
//};

//struct Node {
//	int u, v, lca;
//} query[MAXN];

//vector<Edge> G[MAXN];
//vector<int> Q[MAXN];

//int pre_lca[MAXN], pre_bcj[MAXN];
//ll dist[MAXN];
//bool vis[MAXN];

//void init(int n) {
//	for(int i=1; i<=n; i++)
//		pre_lca[i]=-1, pre_bcj[i]=-1, dist[i]=0, G[i].clear(), Q[i].clear();
//}

//int find_root(int x, int pre[], int n) {
//	int ret = x;
//	while(pre[ret] != -1)
//		ret = pre[ret];
//	return ret;
//}

//void union_xy(int x, int y, int pre[], int n) {
//	int root_x = find_root(x, pre, n);
//	int root_y = find_root(y, pre, n);
//	if(root_x != root_y)
//		pre[root_x] = root_y;
//}

//void dfs(int u, ll d) {
//	vis[u] = true;
//	dist[u] = d;
//	for(int i=0; i<Q[u].size(); i++) {
//		int idx = Q[u][i];
//		if(query[idx].u == u) {
//			if(vis[query[idx].v])
//				query[idx].lca = find_root(query[idx].v, pre_lca, n);
//		} else {
//			if(vis[query[idx].u])
//				query[idx].lca = find_root(query[idx].u, pre_lca, n);
//		}
//	}
//	for(int i=0; i<G[u].size(); i++) {
//		int chl = G[u][i].to;
//		if(vis[chl]) continue ;
//		ll nd = d + G[u][i].val;
//		dfs(chl, nd);
//		pre_lca[chl] = u;
//	}
//}

//int main(void) {
//	freopen("test", "r", stdin);
//	for( ; EOF != scanf("%d %d %d", &n, &m, &t); ) {
//		init(n);
//		for(int i=1; i<=m; i++) {
//			int x, y, d;
//			scanf("%d %d %d", &x, &y, &d);
//			union_xy(x, y, pre_bcj, n);
//			Edge e1(y, d), e2(x, d);
//			G[x].push_back(e1);
//			G[y].push_back(e2);
//		}
//		for(int i=1; i<=t; i++) {
//			scanf("%d %d", &query[i].u, &query[i].v);
//			Q[query[i].u].push_back(i); 
//			Q[query[i].v].push_back(i);
//		}
//		for(int i=1; i<=n; i++) {
//			if(!vis[i] && pre_bcj[i] == -1)
//				dfs(i, 0);
//		}
//		for(int i=1; i<=t; i++) {
//			if(find_root(query[i].v, pre_bcj, n) == find_root(query[i].u, pre_bcj, n)) {
//				int rs = dist[query[i].u]+dist[query[i].v] - 2*(dist[query[i].lca]);
//				printf("%d\n", rs);
//			}
//			else 
//				printf("Not connected\n");
//		}
//		
//	}
//	return 0;
//}













#include <iostream>
#include <vector>
#define MAXN 10005
#define ll long long int
using namespace std;

int n, m, t;
struct Node {
	int u, v, lca;
} query[1000005];

struct Edge {
	int to;
	ll val;
	Edge() : to(0), val(0) { }
	Edge(int _t, int _v) : to(_t), val(_v) { }
};

vector<Edge> G[MAXN];
vector<int> Q[MAXN];
int pre_bcj[MAXN], pre_lca[MAXN], dist[MAXN];
bool vis[MAXN];

void init(int n) {
	for(int i=1; i<=n; i++) 
		pre_lca[i]=-1, pre_bcj[i]=-1, Q[i].clear(), G[i].clear(), vis[i]=false, dist[i]=0;
}

int find_root(int x, int pre[], int n) {
	int ret = x;
	while(pre[ret] != -1) 
		ret = pre[ret];
	if(ret != x)
		pre[x] = ret;
	return ret;
}

void union_xy(int x, int y, int pre[], int n) {
	int root_x = find_root(x, pre, n);
	int root_y = find_root(y, pre, n);
	if(root_x != root_y)
		pre[root_y] = root_x;
}

/**
 * Tarjan求lca的关键是dfs回溯
 * LCA (u, v)
 * 1.访问u的子节点前 先判断与u有关的询问 
 * 		如果vis[v]==true 就 lca(v,u)=find_root(v);
 * 2.dfs(u.sons)
 * 3.设置pre[u.son] = u;
 */
void dfs(int u, int d) {
	vis[u] = true;
	dist[u] = d;
	for(int i=0; i<Q[u].size(); i++) {
		int idx = Q[u][i];
		if(query[idx].u == u) {
			if(vis[query[idx].v])
				query[idx].lca = find_root(query[idx].v, pre_lca, n);
		} else {
			if(vis[query[idx].u]) 
				query[idx].lca = find_root(query[idx].u, pre_lca, n);
		}
	}
	for(int i=0; i<G[u].size(); i++) {
		int chl = G[u][i].to;
		if(vis[chl]) continue ;
		ll nd = G[u][i].val + d;
		dfs(chl, nd);
		pre_lca[chl] = u;
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d %d", &n, &m, &t); ) {
		init(n);
		for(int i=1; i<=m; i++) {
			int x, y, d;
			scanf("%d %d %d", &x, &y, &d);
			Edge e1(y, d), e2(x, d);
			G[x].push_back(e1);
			G[y].push_back(e2);
			union_xy(x, y, pre_bcj, n);
		}
		for(int i=1; i<=t; i++) {
			scanf("%d %d", &query[i].u, &query[i].v);
			Q[query[i].u].push_back(i);
			Q[query[i].v].push_back(i);
		}
		for(int i=1; i<=n; i++) {
			if(!vis[i] && pre_bcj[i]==-1) 
				dfs(i, 0);
		}
		
		for(int i=1; i<=t; i++) {
			if(find_root(query[i].u, pre_bcj, n) != find_root(query[i].v, pre_bcj, n)) {
				printf("Not connected\n");
			} else {
				ll rs = dist[query[i].u]+dist[query[i].v] - 2*(dist[query[i].lca]);
				printf("%lld\n", rs);
			}
		}
	}
	
	
	return 0;
}












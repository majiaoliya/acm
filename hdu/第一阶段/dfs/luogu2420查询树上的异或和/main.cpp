#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100050
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

/**
 * 题意:给定一颗树,有边权,q次查询,每次查节点(u,v)之间的路径异或和
 * 思路:选定一个点为根,dfs出每个节点到根节点的异或和,
 * 查询(u,v)异或和等于ans[u]^ans[v]
 */

int n, m;
int ans[MAXN];
struct Edge {
	int to, w;
};
vector<Edge> G[MAXN];
bool vis[MAXN];

void dfs(int now, int sum, int d) {
	sum ^= d;
	ans[now] = sum;
	vis[now] = true;
	for(int i=0; i<(int)G[now].size(); i++) {
		int chl = G[now][i].to, d = G[now][i].w;
		if(vis[chl]) continue ;
		dfs(chl, sum, d);
	}
	vis[now] = false;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	int u, v, w;
	for(int i=1; i<n; i++) {
		scanf("%d %d %d ", &u, &v, &w);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs(1, 0, 0);
	scanf("%d ", &m);
	while(m--) {
		scanf("%d %d ", &u, &v);
		printf("%d\n", ans[u] ^ ans[v]);
	}






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


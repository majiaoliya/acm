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

int n, m;
vector<int> G[MAXN];
int low[MAXN], dfn[MAXN], timer, flag[MAXN];
bool vis[MAXN];

set<int> ans;
void tarjan(int u, int root) {
	dfn[u] = low[u] = ++ timer;
	int chl_cnt = 0; //记录u的子树个数
	for(auto v : G[u]) {
		if(!dfn[v]) {
			chl_cnt ++;
			tarjan(v, root);
			low[u] = min(low[u], low[v]);
			if(root != u && low[v] >= dfn[u]) { //普通节点,情况二
				ans.insert(u);
			}
		}
		low[u] = min(low[u], dfn[v]);
	}
	if(chl_cnt >= 2 && u == root) { //dfs根节点,情况一
		ans.insert(u);
	}
}

int main() {
#ifdef debug
	freopen("/home/majiao/下载/P3388_1.in", "r", stdin);
	freopen("out", "w", stdout);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int u, v;
		scanf("%d %d ", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) tarjan(i, i);
	printf("%d\n", ans.size());
	for(auto x : ans)
		printf("%d ", x);



#ifdef debug
	clock_t etime = clock();
//	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



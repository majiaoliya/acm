//#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)2e4+7)
#define ll long long int

using namespace std;

/**
 * 题意：去掉树上的一个节点，看看剩下的子树中最大的是多少，然后在这些最大值中求一个最小值，如果有多个点都是最小值，那么找一个序号最小的节点。输出节点号，和最小值。
 */

int n, m, u, v, T, ans, son[MAXN], vis[MAXN], id;
vector<int> G[MAXN];

void init() {
	ans = id = 0x3f3f3f3f;
	for(int i=0; i<=n; i++)
		son[i] = vis[i] = 0, G[i].clear();
}

void dfs(int now) {
	vis[now] = true;
	son[now] = 1;
	int tmax = 0;
	for(int i=0; i<(int)G[now].size(); i++) {
		int chl = G[now][i];
		if(vis[chl]) continue ;
		dfs(chl);
		son[now] += son[chl];
		tmax = max(tmax, son[chl]);
	}
	tmax = max(tmax, n-son[now]);
	if(tmax<ans || (tmax==ans && now<id)) {
		ans = tmax;
		id = now;
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &T);
	while(T--) {
		scanf("%d ", &n);
		init();
		for(int i=1; i<n; i++) {
			scanf("%d %d ", &u, &v);
			G[u].push_back(v), G[v].push_back(u);
		}
		dfs(1);
		printf("%d %d\n", id, ans);
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


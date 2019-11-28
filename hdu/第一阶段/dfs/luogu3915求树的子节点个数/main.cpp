#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

/**
 * 给出n个点的树和k，问能否把树划分成n/k个连通块，且每个连通块的点数都是k
 *  1:满足题目要求的每个联通快一定是这颗树的一个k个节点的子树
 *  2:随便挑选一个节点为根
 *  dfs出每个的子节点个数(+1就是这个节点为根的树的节点个数) 子树节点为k, 计数+1
 */

int n, m, k, vis[MAXN], u, v, ans;
int cnt[MAXN];//记录某个节点为根的子树的大小(节点个数)
vector<int> G[MAXN];

void init() {
	for(int i=1; i<=n; i++)
		G[i].clear(), vis[i] = false, cnt[i] = 0;
}

void dfs(int now) {
	vis[now] = true;
	cnt[now] = 1;
	for(int i=0; i<(int)G[now].size(); i++) {
		int chl = G[now][i];
		if(vis[chl]) continue;
		dfs(chl);
		cnt[now] += cnt[chl];
	}
	if(cnt[now] == k) cnt[now] = 0, ans ++;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	int T;
	scanf("%d ", &T);
	while(T--) {
		scanf("%d %d ", &n, &k);
		init();
		for(int i=1; i<n; i++) {
			scanf("%d %d ", &u, &v);
			G[u].push_back(v), G[v].push_back(u);
		}
		ans = 0;
		if(n%k) { printf("NO\n"); continue ; }
		dfs(1);
		printf("%s\n", ans==(n/k) ? "YES" : "NO");
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 105
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

/**
 * 给定一个无根树,求最小带权路径长度
 * 对每个点dfs水过去了,正解是O(n)的"带权树的重心"
 */

int n, m, u, v, w[MAXN], tmp, vis[MAXN];

vector<int> G[MAXN];

void dfs(int now, int level) {
	tmp += w[now] * level;
	vis[now] = true;
	int cnt = 0;
	for(int i=0; i<(int)G[now].size(); i++) {
		int chl = G[now][i];
		if(vis[chl]) continue ;
		vis[chl] = true;
		cnt ++;
		dfs(chl, level+1);
		vis[chl] = false;
	}
	vis[now] = false;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) {
		int x, y, z;
		scanf("%d %d %d ", &z, &x, &y);
		w[i] = z;
		if(x) G[x].push_back(i), G[i].push_back(x);
		if(y) G[y].push_back(i), G[i].push_back(y);
	}

	int ans = 0x3f3f3f3f;
	for(int i=1; i<=n; i++) {
		tmp = 0;
		dfs(i, 0);
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


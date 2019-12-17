#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 505
#include <map>
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给定图,求一个节点,要求这个节点到其他节点的最短路径最长边最小
 * floyd最小化最长边
 */
int n, m, mp[MAXN][MAXN], pre[MAXN];

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1) ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry) pre[ry] = rx;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d ", &n) && n) {
		scanf("%d ", &m);
		memset(mp, 0x3f3f3f3f, sizeof(mp));
		memset(pre, -1, sizeof(pre));
		int u, v, w;
		for(int i=1; i<=m; i++) {
			scanf("%d %d %d ", &u, &v, &w);
			mp[u][v] = mp[v][u] = w;
			union_xy(u, v);
		}
		int cnt = 0;
		for(int i=0; i<n; i++)
			if(pre[i] == -1) cnt ++;
		if(cnt > 1) {
			printf("-1\n");
			continue ;
		}
		int ans = -1;
		for(int k=0; k<n; k++) { //floyd-改
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(mp[i][j] > max(mp[k][i], mp[k][j])) {
						mp[i][j] = max(mp[k][i], mp[k][j]);
						ans = k;
					}
				}
			}
		}
		printf("%d\n", ans);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



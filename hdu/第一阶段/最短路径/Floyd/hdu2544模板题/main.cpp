#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 128
#include <map>
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, mp[MAXN][MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m) && (n+m)) {
		memset(mp, 0x3f3f3f3f, sizeof(mp));
		for(int i=1; i<=m; i++) {
			int u, v, w;
			scanf("%d %d %d ", &u, &v, &w);
			mp[u][v] = mp[v][u] = w;
		}
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					mp[i][j] = min(mp[i][j], mp[k][i]+mp[k][j]);
		printf("%d\n", mp[1][n]);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


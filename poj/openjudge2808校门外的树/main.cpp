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
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, vis[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int l, r;
		scanf("%d %d ", &l, &r);
		if(l > r) swap(l, r);
		for( ; l<=r; l++) vis[l] = true;
	}
	int ans = 0;
	for(int i=0; i<=n; i++) if(vis[i] == 0) ans ++;
	printf("%d\n", ans);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



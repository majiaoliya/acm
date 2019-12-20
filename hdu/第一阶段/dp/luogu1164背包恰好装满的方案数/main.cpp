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
#define MAXN ((int)2e4+7)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 背包容量m,物品arr[ ], 问恰好装满的方案数
 * dp[i][k]表示背包容量为k装第i个商品时的方案数
 */

int n, m, arr[MAXN], dp[MAXN][MAXN]; 

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d ", arr+i);
	for(int i=0; i<=n; i++)
		dp[i][0] = 1;
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=m; k++) {
			dp[i][k] = dp[i-1][k];
			if(k >= arr[i]) dp[i][k] += dp[i-1][k-arr[i]];
		}
	}
	printf("%d\n", dp[n][m]);
//	for(int i=1; i<=n; i++)
//		forarr(dp[i], 1, m);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



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
#include <queue>
#define MAXN ((int)512)
#define ll long long int
#define ld long double
#define QAQ (0)

using namespace std;

/**
 * 两个权值的01背包 多套一个for即可
 * dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-w1[i]][k-w2[i]])
 */

int n, ma, mb, wa[MAXN], wb[MAXN], p[MAXN];
int dp[MAXN][MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d ", &ma, &mb, &n);
	for(int i=1; i<=n; i++) 
		scanf("%d %d %d ", wa+i, wb+i, p+i);
	for(int i=1; i<=n; i++) {
		for(int j=ma; j>=wa[i]; j--) {
			for(int k=mb; k>=wb[i]; k--) {
				dp[j][k] = max(dp[j][k], dp[j-wa[i]][k-wb[i]]+p[i]);
			}
		}
	}
	printf("%d\n", dp[ma][mb]);




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



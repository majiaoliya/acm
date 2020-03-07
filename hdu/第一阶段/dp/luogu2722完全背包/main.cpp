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
#include <math.h>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define PARSE(x) ((x>='a' && x<='z') ? x-'a' : x-'A')
#define QAQ (0)

using namespace std;

template <typename T>
T abs(T val) { val > 0 ? val : -val; }

int n, m, dp[MAXN], w[MAXN], p[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	cin >> m >> n;
	for(int i=1; i<=n; i++) cin >> p[i] >> w[i];
	for(int i=1; i<=n; i++)
		for(int k=w[i]; k<=m; k++) //完全背包正好是01的反过来
								   //01是 m->w[i]
								   //完全是 w[i]->m
			dp[k] = max(dp[k], dp[k-w[i]]+p[i]);
	printf("%d\n", dp[m]);


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




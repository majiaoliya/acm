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

//选取和不超过S的若干个不同的正整数，使得所有数的约数（不含它本身）之和最大
//先筛法求约数和, 在01背包
int n, p[MAXN], pn, dp[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<n; i++) {
		for(int k=2; k*i<=n; k++)
			p[i*k] += i;
	}
//	forarr(p, 1, n);
	for(int i=1; i<=n; i++)
		for(int k=n; k>=i; k--)
			dp[k] = max(dp[k], dp[k-i]+p[i]);
	printf("%d\n", dp[n]);








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



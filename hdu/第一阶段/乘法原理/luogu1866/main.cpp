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
#define PARSE(x) ((x>='a' && x<='z') ? x-'a' : x-'A')
#define QAQ (0)

using namespace std;

int a, c, p, q, r, x;
template <typename T>
T abs(T val) { val > 0 ? val : -val; }

const int mod = 1000000007;
int n, m, arr[MAXN];
ll dp[MAXN]; //注意要开long long下面乘起来爆int

/**
 * 题意: n只兔子选编号,第i只想要[1,a[i]]内的编号,每个编号只能选一次
 *      问有多少中选法
 * 思路: 乘法原理类似
 *      先排个序, 第一只兔子有a[1]种选法, 第二只有a[2]-1种选法,
 *      第三只有a[3]-2种.....第n只有a[n]-(n-1)种
 *      乘起来就是答案
 */

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) scanf("%d ", arr+i);
	sort(arr+1, arr+1+n);
	dp[1] = arr[1];
	for(int i=2; i<=n; i++) {
		int k = arr[i]-i+1;
		dp[i] = dp[i-1] * k;
		dp[i] %= mod;
//		dp[i] = ((dp[i-1]%mod) * (k%mod))%mod;
	}
	printf("%lld\n", dp[n]);

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




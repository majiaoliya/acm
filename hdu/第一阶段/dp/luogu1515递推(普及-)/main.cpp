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

/**
 * 题目:给定多个旅馆a[i],规定每天走最少走A米, 最多走B米
 *      问到终点有多少种方案
 * 思路: 递推
 * 		对于每一个旅馆,只会从前面(B-A)米内的多个旅馆转移过来
 */

int n, m, x, vis[MAXN], A, B, dp[MAXN];
int arr[MAXN] = {
	0, 0,  990, 1010, 1970, 2030, 2940, 3060, 
	3930, 4060, 4970, 5030, 5990, 6010, 7000
};

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d ", &A, &B, &m);
	n = 14;
//	forarr(arr, 1, n);
	while(m--) scanf("%d ", &arr[++n]);
	sort(arr+1, arr+n+1);
//	forarr(arr, 1, n);
	dp[1] = 1;
	for(int i=2; i<=n; i++) {
		int len = 0;
		for(int k=i-1; k>=1; k--) {
			len += arr[k+1]-arr[k];
			if(len>=A && len<=B) dp[i] += dp[k];
		}
	}
	printf("%d\n", dp[n]);

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




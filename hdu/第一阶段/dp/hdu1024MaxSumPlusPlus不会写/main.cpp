
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 10005
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int arr[MAXN], n, m, dp[MAXN][MAXN];

int main()
{
	freopen("test", "r", stdin);
	while(EOF != scanf("%d %d", &m, &n)) {
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		/**
		 * dp[0][i] = 0;
		 * dp[1][i] = max(arr[i1, i2, i3 ... iN])
		 * dp[n][i] = max(dp[n-1][i1], dp[n-1][i2].....dp[n-1][iN])
		 */
		memset(dp, false, sizeof(dp));
		for(int i=1; i<=n; i++) {
			for(int k=1)
		}
	}

	return 0;
}




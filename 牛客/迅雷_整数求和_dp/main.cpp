#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

#define MAXN 128

int n, m, dp[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		memset(dp, false, sizeof(dp));
		dp[0] = 1;
		for(int i=1; i<=n; i++)
			for(int k=m; k>=i; k--)
				dp[k] = dp[k]+dp[k-i];
		printf("%d\n", dp[m]);
	}
	return 0;
}

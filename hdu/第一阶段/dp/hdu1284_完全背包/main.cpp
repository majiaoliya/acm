#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN (32768)
#define ll long long  
using namespace std;

int n, dp[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n)) {
		memset(dp, false, sizeof(dp));
//		dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = ;
		dp[0] = 1;
		int arr[] = { 0, 1, 2, 3 };
		for(int i=1; i<=3; i++)
			for(int k=arr[i]; k<=n; k++)
				dp[k] += dp[k-arr[i]];
//				dp[k] = max(dp[k], dp[k-arr[i]]+arr[i]);
		printf("%d\n", dp[n]);
	}
	return 0;
}

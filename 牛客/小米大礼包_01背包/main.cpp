#include <iostream>
#include <set>
#include <vector>
#include <queue>
#define MAXN 9999999
using namespace std;

int n, m, w[MAXN], dp[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", w+i);
	scanf("%d", &m);
	for(int i=1; i<=n; i++)
		for(int k=m; k>=w[i]; k--)
			dp[k] = max(dp[k], dp[k-w[i]]+w[i]);
	printf("%d\n", dp[m]==m ? 1 : 0);
	return 0;
}

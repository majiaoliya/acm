#include <iostream>
#include <set>
#include <vector>
#include <queue>
#define MAXN 1005
using namespace std;

int n, m, w[MAXN], p[MAXN], dp[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &m);
	getchar();
	scanf("%d", &n);
	getchar();
	for(int i=1; i<=n; i++)
		scanf("%d", w+i);
	getchar();
	for(int i=1; i<=n; i++)
		scanf("%d", p+i);
	for(int i=1; i<=n; i++)
		for(int k=m; k>=w[i]; k--)
			dp[k] = max(dp[k], dp[k-w[i]] + p[i]);
	printf("%d\n", dp[m]);
	return 0;
}

#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 1005
#define ll long long  
using namespace std;

int t, n, m, w[MAXN], v[MAXN], dp[MAXN];

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		memset(dp, false, sizeof(dp));
		for(int i=1; i<=n; i++)
			scanf("%d", v+i);
		for(int i=1; i<=n; i++)
			scanf("%d", w+i);
		for(int i=1; i<=n; i++)
			for(int k=m; k>=w[i]; k--) {
				dp[k] = max(dp[k], dp[k-w[i]]+v[i]);
			}
		printf("%d\n", dp[m]);
	}
	
	return 0;
}




#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 1005
#define ll long long  
using namespace std;

//这题里面 w[i] = v[i]
int t, n, m, w[MAXN], v[MAXN], dp[MAXN];

int main()
{
	freopen("test", "r", stdin);
	while(~scanf("%d", &n) && n) {
		for(int i=1; i<=n; i++)
			scanf("%d", w+i);
		scanf("%d", &m);
		if(m < 5) {
			printf("%d\n", m);
			continue ;
		}
		memset(dp, false, sizeof(dp));
		sort(w+1, w+1+n);
		int V = m - 5;
		for(int i=1; i<=n-1; i++)
			for(int k=V; k>=w[i]; k--)
				dp[k] = max(dp[k], dp[k-w[i]]+w[i]);
		printf("%d\n", m-dp[V]-w[n]);
	}
	return 0;
}




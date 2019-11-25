#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define MAXN 100005

int n, m, arr[MAXN], dp[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d", &m, &n);
	for(int i=1; i<=n; i++) scanf("%d", arr+i);
	for(int i=1; i<=n; i++)
		for(int k=m; k>=arr[i]; k--)
			dp[k] = max(dp[k], dp[k-arr[i]]+arr[i]);
	printf("%d\n", m-dp[m]);
	return 0;
}




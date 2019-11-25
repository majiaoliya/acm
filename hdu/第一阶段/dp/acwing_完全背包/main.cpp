#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 1005
#define ll long long  
using namespace std;

int n, m, w[MAXN], v[MAXN], dp[MAXN];

int main()
{
	freopen("test", "r", stdin);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		cin >> v[i] >> w[i];
	for(int i=1; i<=n; i++)
		for(int k=v[i]; k<=m; k++)
			dp[k] = max(dp[k], dp[k-v[i]]+w[i]);
	cout << dp[m] << endl;
	return 0;
}




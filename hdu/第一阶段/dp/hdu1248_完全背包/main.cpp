#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 10005
#define ll long long  
using namespace std;

int t, m;
int w[] = { 0, 150, 200, 350 };
int dp[MAXN];

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &m);
		memset(dp, false, sizeof(dp));
		for(int i=1; i<=3; i++)
			for(int k=w[i]; k<=m; k++) 
				dp[k] = max(dp[k], dp[k-w[i]]+w[i]);
		printf("%d\n", m-dp[m]);
	}
	return 0;
}




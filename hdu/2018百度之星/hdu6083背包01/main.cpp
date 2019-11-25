#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define min(x,y) ( x > y ? y : x )
#define ll long long int
#define MAXN 10005
using namespace std;

int n, m, w[MAXN], p[MAXN], dp[MAXN][MAXN];

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &m, &n);
		for(int i=1; i<=n; i++) 
			scanf("%d %d", p+i, w+i);
		for(int i=1; i<=n; i++)
			for(int k=1; k<=m; k++) {
				if(k < w[i]) dp[i][k] = dp[i-1][k];
				else dp[i][k] = max(dp[i-1][k], dp[i-1][k-w[i]]+p[i]);
			}
		for(int i=1; i<=n; i++) {
			for(int k=1; k<=m; k++)
				printf("%d ", dp[i][k]);
			printf("\n");
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}

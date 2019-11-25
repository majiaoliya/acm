#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 10005
#define ll long long
using namespace std;

int t, m, n, x, y, sum[MAXN][MAXN];

int main() {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &m, &n, &x, &y);
		for(int i=1, a; i<=m; i++)
			for(int k=1; k<=n; k++) {
				scanf("%d", &a);
				sum[i][k] = sum[i][k-1]+sum[i-1][k] + a - sum[i-1][k-1];
			}
		int rs = 0;
		for(int i=x; i<=m; i++)
			for(int k=y; k<=n; k++)
				rs = max(rs, sum[i][k]-sum[i-x][k]-sum[i][k-y]+sum[i-x][k-y]);
		printf("%d\n", rs);
	}
	return 0;
}


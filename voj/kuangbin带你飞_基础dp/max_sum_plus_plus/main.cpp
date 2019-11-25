#include <iostream>

using namespace std;

int n, m, arr[MAXN], dp[MAXN][MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(EOF != scanf("%d %d", &m, &n)) {
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		int rs = 0;
		for(int i=1; i<=n; i++) {
			dp[i][i] = arr[i];
			for(int k=1; k<i; k++) {
				int temp = dp[i-1][k];

			}
		}
	}
	return 0;
}

// 尺取法
#include <iostream>

using namespace std;

const int MAXN = 1e5+7;

int t, n, m, arr[MAXN], sum[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i), sum[i] = sum[i-1] + arr[i];
		int rs = n+3, i = 1, j = 1, tsum = 0;
		for( ; ; ) {
			while(tsum < m && j<=n) {
				tsum += arr[j];
				j ++;
			}
			if(tsum < m) break;
			rs = min(rs, j-i);
			tsum -= arr[i];
			i++;
		}
		printf("%d\n", rs>n ? 0 : rs);
	}
	return 0;
}



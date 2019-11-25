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
			scanf("%d", arr+i), sum[i] = sum[i-1]+arr[i];
		if(sum[n] < m) {
			printf("%d\n", 0);
			continue ;
		}
		int s = 1, t = 1, tsum = 0, rs = n+1;
		for( ; ; ) {
			while(t<=n && tsum<m) {
				tsum += arr[t];
				t ++;
			}
			if(tsum < m) 
				break;
			rs = min(rs, t-s);
			tsum -= arr[s++];
		}
		printf("%d\n", rs > n ? 0 : rs);
	}
	return 0;
}



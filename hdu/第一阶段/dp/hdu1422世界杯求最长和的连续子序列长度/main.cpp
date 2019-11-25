
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN (200005)
#define ll long long int
using namespace std;

int n, arr[MAXN], ans[MAXN];

int main() {
	freopen("test", "r", stdin);
	while(EOF != scanf("%d", &n)) {
		for(int i=0, x, y; i<n; i++) {
			scanf("%d %d", &x, &y);
			arr[i] = arr[i+n] = x-y;
			ans[i] = ans[i+n] = 1;
		}
		
		int rs = 0;
		for(int i=1; i<2*n; i++) {
			if(arr[i]+arr[i-1]>=0 && arr[i-1]>=0) {
				arr[i] = arr[i] + arr[i-1];
				ans[i] += ans[i-1];
				if(ans[i] == n) break;
			}
		}
		for(int i=1; i<2*n; i++)
			rs = max(rs, ans[i]);

		/**
		for(int i=1; i<n*2; i++) {
			sum += arr[i];
			if(sum >= 0) {
				cnt ++;
			} else {
				sum = arr[i];
				cnt = 0;
			}
			rs = max(cnt, rs);
		}
		*/
		printf("%d\n", rs>n ? n : rs);
	}

	return 0;
}




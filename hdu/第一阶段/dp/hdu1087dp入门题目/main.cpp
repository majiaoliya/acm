#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 5005
using namespace std;

int arr[MAXN], dp[MAXN], n;

int main() {
	freopen("test", "r", stdin);
	/**
	while(~scanf("%d", &n) && n) {
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			dp[i] = arr[i];
		}
		int tmax = 0;
		for(int i=1; i<=n; i++) {
			for(int k=1; k<=i; k++) {
				if(arr[i] > arr[k] && dp[i] < dp[k]+arr[i])
					dp[i] = dp[k] + arr[i];
			}
			tmax = max(dp[i], tmax);
		}
		printf("%d\n", tmax);
	}
	*/

	while(~scanf("%d", &n) && n) {
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			dp[i] = arr[i];
		}
		int tmax = -1;
		for(int i=1; i<=n; i++) {
			for(int k=1; k<i; k++) {
				if(arr[i] > arr[k] && dp[k]+arr[i] > dp[i])
					dp[i] = dp[k] + arr[i];
			}
			tmax = max(tmax, dp[i]);
		}
		if(tmax == -1) printf("NO\n");
		else printf("%d\n", tmax);
	}

	return 0;
}





#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 5005
using namespace std;

int n, dp[MAXN], arr[MAXN];

int main() {
	freopen("test", "r", stdin);
	while(EOF != scanf("%d", &n)) {
		for(int i=1; i<=n; i++) 
			scanf("%d", arr+i);
		for(int i=1; i<=n; i++)
			dp[i] = 1;
		int rs = 0;
		for(int i=1; i<=n; i++) {
			for(int k=1; k<i; k++) {
				if(arr[i] > arr[k])
					dp[i] = max(dp[i], dp[k]+1);
			}
			rs = max(dp[i], rs);
		}
		printf("%d\n", rs);
	}
	return 0;
}




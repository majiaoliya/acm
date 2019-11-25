#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 10005
#define ll long long  
using namespace std;
/** MLE 
int t, n, arr[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			for(int k=1; k<=i; k++) {
				scanf("%d", &arr[i][k]);
			}
		}
		memset(dp, false, sizeof(dp));
		dp[1][1] = arr[1][1];
		int rs = 0;
		for(int i=1; i<=n; i++) {
			for(int k=1; k<=i; k++) {
				if(k==1) dp[i][k] = dp[i-1][k] + arr[i][k];
				else dp[i][k] = max(dp[i-1][k]+arr[i][k], dp[i-1][k-1]+arr[i][k]);
				rs = max(dp[i][k], rs);
			}
		}
		printf("%d\n", rs);
	}
	return 0;
}

*/

#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 10005
#define ll long long
using namespace std;

int t, n, dp[MAXN][MAXN];

int main() {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int rs = 0;
		for(int i=1; i<=n; i++) {
			for(int k=1; k<=i; k++) {
				scanf("%d", &dp[i][k]);
				if(k == 1) dp[i][k] += dp[i-1][k];
				else dp[i][k] = max(dp[i][k]+dp[i-1][k], dp[i][k]+dp[i-1][k-1]);
				rs = max(dp[i][k], rs);
			}
		}
		printf("%d\n", rs);
	}
	return 0;
}


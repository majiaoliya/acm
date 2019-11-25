#include <iostream>
#include <set>
#include <vector>
#include <queue>
#define MAXN 9999999
using namespace std;

int n, arr[MAXN], dp[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(true) {
		if(EOF == scanf("%d", arr+n)) break;
		n ++;
		getchar();
	}
	dp[0] = dp[1] = 0;
	for(int i=2; i<=n; i++)
		dp[i] = min(dp[i-1]+arr[i-1], dp[i-2]+arr[i-2]);
	printf("%d\n", dp[n]);
	//for(int i=0; i<=n; i++)
	//	printf("%d ", dp[i]);
	return 0;
}

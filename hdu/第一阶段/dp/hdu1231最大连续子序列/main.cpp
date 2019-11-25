#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 5005
using namespace std;

int n, arr[MAXN], cnt, tmax;

int main() {
	freopen("test", "r", stdin);

	while(~scanf("%d", &n) && n) {
		for(int i=1; i<=n; i++) 
			scanf("%d", arr+i);
		int rsid=1, dp[MAXN] = { 0 }, lef = arr[1], rig = arr[1];
		//dp方程为 : dp[i]=max(dp[i-1]+a[i],a[i]);
		for(int i=1; i<=n; i++) {
			dp[i] = max(arr[i], dp[i-1]+arr[i]);
			if(dp[rsid] < dp[i]) {
				rsid = i;
				rig = arr[i];
			}
		}	
		for(int i=rsid; i>=1; i--) {
			if(dp[i] < 0) break;
			lef = arr[i];
		}
		if(dp[rsid] < 0) printf("0 %d %d\n", arr[1], arr[n]);
		else printf("%d %d %d\n", dp[rsid], lef, rig);
//		printf("%d %d %d\n", (dp[rsid]==-1 ? 0:dp[rsid]), lef, rig);
	//	for(int i=1; i<=n; i++)
	//		printf("%d  ", dp[i]);
	//	printf("\n\n");
	}

	return 0;
}




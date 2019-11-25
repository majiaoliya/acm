#include<time.h>
#include<limits.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MAXN = 10005;
int n, arr[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int k=1; k<=n; k++) {
			scanf("%d", &arr[i][k]);
			getchar();
		}
	for(int i=0; i<=n; i++) {
		for(int k=0; k<=n; k++) {
			dp[i][k] = 9999999;
//			printf("%d,", arr[i][k]);
		}
//		printf("\n");
	}
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=n; k++) {
			if(i == k && k == 1) dp[i][k] = arr[i][k];
			else dp[i][k] = min(dp[i-1][k]+arr[i][k], dp[i][k-1]+arr[i][k]);
		}
	}
	printf("%d\n", dp[n][n]);
//	for(int i=1; i<=n; i++) {
//		for(int k=1; k<=n; k++) {
//			printf("%d,", dp[i][k]);
//		}
//		printf("\n");
//	}
	return 0;
}


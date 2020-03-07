//#include <iostream> 
//#include <string.h>
//#include <vector>
//#include <time.h>
//using namespace std;
//#include <iostream>
//#include <math.h>
//#include <vector>
//#define MAXN 1005
//#define ll long long int
//using namespace std;
//
///**
//  dp[i][j]表示前i个物品,体积为j时 的最大价值
//  result = max(dp[n][0~V])
//  1.不选第i个 dp[i][j] = dp[i-1][j]
//  2.选择第i个 dp[i][j] = dp[i-1][j-w[i]]
//  dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]])
// */
//int n, v, w[MAXN], p[MAXN], dp[MAXN][MAXN], dp1[MAXN];
//int pre[MAXN][MAXN];
//
//int main(void) {
//	freopen("test", "r", stdin);
//	scanf("%d %d", &n, &v);
//	for(int i=1; i<=n; i++) 
//		scanf("%d %d", w+i, p+i);
//	for(int i=1; i<=n; i++) {
//		for(int k=1; k<=v; k++) {
//			if(k<w[i]) { //装不进
//				dp[i][k] = dp[i-1][k];
//				pre[i][k] = pre[i-1][k];
//			} else {
//				if(dp[i-1][k]<dp[i-1][k-w[i]]+p[i]) 
//					pre[i][k] = pre[i-1][k-w[i]];
//				else
//					pre[i][k] = pre[i-1][k];
//				dp[i][k] = max(dp[i-1][k], dp[i-1][k-w[i]]+p[i]);
//			}
//		}
//	}
//	printf("%d\n", dp[n][v]);
//	for(int i=1; i<=n; i++) {
//		for(int k=1; k<=v; k++) printf("%d ", dp[i][k]);
//		printf("\n");
//	}
//	/** 二维
//	for(int i=1; i<=n; i++)
//		for(int k=v; k>=w[i]; k--)
//			dp1[k] = max(dp1[k], dp1[k-w[i]]+p[i]);
//	
//	printf("%d\n", dp1[v]);
//	*/
//	return 0;
//}
//
//






#include <iostream> 
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;
#include <iostream>
#include <math.h>
#include <vector>
#define MAXN 1005
#define ll long long int
using namespace std;

/**
  dp[i][j]表示前i个物品,体积为j时 的最大价值
  result = max(dp[n][0~V])
  1.不选第i个 dp[i][j] = dp[i-1][j]
  2.选择第i个 dp[i][j] = dp[i-1][j-w[i]]
  dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]])
 */
int n, v, w[MAXN], p[MAXN], dp[MAXN][MAXN], dp1[MAXN];
int pre[MAXN][MAXN];
int item[MAXN];

void bt(int i, int j) { //回溯查找解
	if(i>0) {
		if(dp[i][j] == dp[i-1][j]) {
			item[i] = 0;
			bt(i-1, j);
		} else if(j-w[i]>=0 && dp[i][j]==dp[i-1][j-w[i]]+p[i]) {
			item[i] = 1;
			bt(i-1, j-w[i]);
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &v);
	for(int i=1; i<=n; i++) 
		scanf("%d %d", w+i, p+i);
	int m = v;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(j<w[i]) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+p[i]);
			}
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", dp[n][v]);
	bt(n, v); //回溯解空间
	for(int i=1; i<=n; i++)
		printf("%d\n", item[i]);
	return 0;
}











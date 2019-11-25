#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN (255557)
#define ll long long  
using namespace std;

int n, an, sum, w[MAXN], dp[MAXN];
/**
int main()
{
	freopen("test", "r", stdin);
	while(~scanf("%d", &n) && n!=-1) {
		memset(dp, false, sizeof(dp));
		an = 1, sum = 0;
		for(int i=1; i<=n; i++) {
			int x, t;
			scanf("%d %d", &x, &t);
//			printf("t*x = %d*%d = %d\n", t, x, t*x);
//			sum += t*x;
			for(int k=1; k<=t; k++) {
				w[an++] = x;
				sum += x;
			}
		}
		int V = sum >> 1;
		for(int i=1; i<an; i++)
			for(int k=V; k>=w[i]; k--)
				dp[k] = max(dp[k], dp[k-w[i]]+w[i]);
//		printf("sum:%d %d %d\n", sum, sum-dp[V], dp[V]);
		printf("%d %d\n", sum-dp[V], dp[V]);
	}
	return 0;
}
*/

/**
int main(void) {
	freopen("test", "r", stdin);

	while(~scanf("%d", &n) && n>0) {
		memset(w, false, sizeof(w));
		memset(dp, false, sizeof(dp));
		an = sum = 0;
		for(int i=0; i<n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			for(int k=0; k<b; k++) {
				w[an++] = a;
				sum += a;
			}
		}
		int V = sum / 2;
		for(int i=0; i<n; i++) {
			for(int k=V; k>=w[i]; k--)
				dp[k] = max(dp[k], dp[k-w[i]] + w[i]);
		}
		printf("%d %d\n", sum-dp[V], dp[V]);
	}

	return 0;
}
*/


int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n) && n>0) {
		an = sum = 0;
		memset(w, false, sizeof(w));
		memset(dp, false, sizeof(dp));
		for(int i=0; i<n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			while(b--) {
				w[an++] = a;
				sum += a;
			}
		}
		for(int i=0; i<an; i++)
			for(int k=sum/2; k>=w[i]; k--)
				dp[k] = max(dp[k], dp[k-w[i]]+w[i]);
		printf("%d %d\n", sum-dp[sum/2], dp[sum/2]);
	}
	return 0;
}

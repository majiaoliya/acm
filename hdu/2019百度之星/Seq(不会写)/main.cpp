#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define min(x,y) ( x > y ? y : x )
#define ll long long int
#define MAXN 10005
using namespace std;

int t, n;

int main(void) {
	freopen("test", "r", stdin);
	n = 100;
	int dp[n+3] = { 0 };
	dp[1] = 1;
	for(int i=2; i<=n; i++) {
		int sum = 0;
		for(int k=1; k<=i-1; k++) {
			sum += dp[k]*k;
		}
		dp[i] = sum % i;
	}
	for(int i=1; i<=n; i++) {
		printf("%d", dp[i]%6);
		if(i%36 == 0) printf("\n");
	}
	for(int i=2; i<=n; i++) {
		bool ok = true;
		for(int k=1; k<i; k++) {
			if(dp[k] != dp[k+i]) {
				ok = false;
				break;
			}
		}
		if(ok) {
			printf("find loop %d\n", i);
			break;
		}
	}
	return 0;
}

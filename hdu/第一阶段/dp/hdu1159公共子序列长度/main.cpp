#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 10005
#define ll long long  
using namespace std;

char a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main()
{
	freopen("test", "r", stdin);
	while(~scanf("%s%s", a+1, b+1)) {
		int an = strlen(a+1), bn = strlen(b+1);
		for(int i=1; i<=an; i++) {
			for(int k=1; k<=bn; k++) {
				if(a[i] == b[k]) dp[i][k] = dp[i-1][k-1] + 1;
				else dp[i][k] = max(dp[i-1][k], dp[i][k-1]);
			}
		}
		printf("%d\n", dp[an][bn]);
	}
	return 0;
}




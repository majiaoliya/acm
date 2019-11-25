
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 5005
using namespace std;

char s1[MAXN], s2[MAXN];
int dp[MAXN][MAXN], len1, len2;

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	freopen("test", "r", stdin);
	while(EOF != scanf("%s %s", s1+1, s2+1)) {
		len1 = strlen(s1+1), len2 = strlen(s2+1);
		int rs = 0;
		for(int i=1; i<=len1; i++) {
			for(int k=1; k<=len2; k++) {
				if(s1[i] == s2[k]) 
					dp[i][k] = dp[i-1][k-1] + 1;
				else
					dp[i][k] = max(dp[i-1][k], dp[i][k-1]);
				rs = max(dp[i][k], rs);
			}
		}
		printf("%d\n", rs);
	}
	return 0;
}




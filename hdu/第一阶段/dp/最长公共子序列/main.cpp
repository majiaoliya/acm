
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 5005
using namespace std;

char s1[MAXN], s2[MAXN];
int dp[MAXN][MAXN], len1, len2;

int main()
{
	freopen("test", "r", stdin);
	scanf("%s %s", s1+1, s2+1);
	len1 = strlen(s1+1), len2 = strlen(s2+1);

	for(int i=1; i<=len1; i++) {
		for(int k=1; k<=len2; k++) {
			if(s2[k] == s1[i])
				dp[i][k] = max(dp[i][k-1] + 1, dp[i-1][k]+1);
			else 
				dp[i][k] = max(dp[i-1][k], dp[i][k-1]);
		}
	}

	for(int i=1; i<=len1; i++) {
		for(int k=1; k<=len2; k++) {
			printf("%d  ", dp[i][k]);
		}
		printf("\n");
	}
	return 0;
}




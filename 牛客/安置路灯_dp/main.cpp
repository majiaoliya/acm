#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 300005
#include <map>
#define ll long long int
#define max(x, y) ( x > y ? x : y )

using namespace std;

int t, len, dp[2048];
char str[2048];

int main() {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &len);
		scanf("%s", str+1);
		dp[1] = str[1]=='.' ? 1 : 0;
		for(int i=2; i<=len; i++) {
			dp[i] = 
		}
	}
	return 0;
}





#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 32

using namespace std;
typedef unsigned long long ull;

int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int x, y, mx, my;
ull dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main() {
	freopen("test", "r", stdin);
	scanf("%d %d %d %d", &x, &y, &mx, &my);
	x++, y++, mx++, my++;
	vis[mx][my] = true;
	dp[1][1] = 1;
	for(int i=1; i<=8; i++)
		vis[mx+dx[i]][my+dy[i]] = true;
	
	for(int i=1; i<=x; i++) {
		for(int k=1; k<=y; k++) {
			if(vis[i][k]) continue ;
		   	dp[i][k] = max(dp[i][k], dp[i-1][k]+dp[i][k-1]);
		}
	}
	printf("%llu\n", dp[x][y]);
	
	return 0;
}




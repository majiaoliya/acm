#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 10005

using namespace std;
int n, m, k;
int cost[MAX], value[MAX], pre[MAX];

int find_root(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x) 
		pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int root_x = find_root(x);
	int root_y = find_root(y);
	if(root_x != root_y) {
		pre[root_y] = root_x;
	}
}

int main()
{
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d %d %d", &n, &m, &k);
		for(int i=1; i<=n; i++) //初始化
			cost[i] = 0, value[i] = 0, pre[i] = -1;
		for(int i=2; i<=n; i++) 
			scanf("%d %d", cost+i, value+i);
		for(int i=0; i<m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			union_xy(x, y);
		}
		for(int i=1; i<=n; i++)
			printf("%d,", pre[i]);
		int dp[n+1][500+1];
		for(int i=0; i<n+1; i++) memset(dp[i], false, sizeof(dp[i]));
		for(int i=2; i<=n; i++) {
			if(pre[i] != 1) continue ; //没有交集
			for(int cap=1; cap<500; cap++) {
				
			}
		}
	}
		
	return 0;
}


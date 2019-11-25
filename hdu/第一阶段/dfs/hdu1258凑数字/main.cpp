#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXN 32
using namespace std;

int t, n, arr[MAXN], rs[MAXN], cnt;
bool vis[MAXN];
int cmp(int a, int b) { return a > b; }

void dfs(int x, int sum) {
	if(sum == t) {
		cnt ++;
		for(int i=1; i<x; i++) {
			if(i != 1) printf("+");
			printf("%d", arr[rs[i]]);
		}
		printf("\n");
		return ;
	}
	if(x == n+1) return ;
	if(sum > t) return ;
	for(int i=x; i<=n; i++) {
		if(vis[i] || i < rs[x-1]) continue ;
		vis[i] = true;
		rs[x] = i;
		dfs(x+1, sum+arr[i]);
		vis[i] = false;
		while(i+1<=n && arr[i]==arr[i+1])
			i++;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	while(scanf("%d %d", &t, &n) && (t+n)) {
		int tsum = 0;
		memset(vis, false, sizeof(vis));
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			tsum += arr[i];
		}	
		printf("Sums of %d:\n", t);
		if(tsum < t) {
			printf("NONE\n");
			continue;
		}
		sort(arr+1, arr+1+n, cmp);
		for(int i=1; i<=n; i++)
			rs[i] = i;
		cnt = 0;
		dfs(1, 0);
		if(cnt == 0) printf("NONE\n");
	}
	return 0;
}

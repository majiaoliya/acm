#include <iostream>
#include <string.h>
#define MAXN 32
using namespace std;

int t, arr[MAXN], ans;
const int INF = 1e9+7;
bool vis[MAXN];

void dfs(int x, int sum) {
	if(sum >= ans) return ;
	if(x == 9) {
		ans = sum;
		return ;
	}
	for(int i=1; i<=9; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		for(int k=i+1; k<=10; k++) {
			if(vis[k]) continue ;
			dfs(x+1, sum+abs(arr[k]-arr[i]));
			break;
		}
		vis[i] = false;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		for(int i=1, x; i<=10; i++) {
			scanf("%d", &x);
			arr[x] = i;
		}
		memset(vis, false, sizeof(vis));
		ans = INF;
		dfs(0, 0);
		printf("%d\n", ans);
	}

	return 0;
}

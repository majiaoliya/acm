#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 11

using namespace std;

int n, m;

int arr[MAXN], rs[MAXN];
bool vis[MAXN], ok = false;

void dfs(int x, int sum) {
	if(ok) return;
	if(x == n+1) {
		ok = true;
		printf("%d\n", sum);
		return ;
	}
	for(int i=1; i<=9; i++) {
		if(vis[i]) continue;
		rs[x] = i;
		vis[i] = true;
		int tsum = sum*10 + i;
		if(tsum%x == 0) dfs(x+1, tsum);
		vis[i] = false;
	}
}

int main()
{	
	for(int i=1; i<10; i++)
		arr[i] = i;
	freopen("test", "r", stdin);
	for( ; cin>>n; ) {
		ok = false;
		memset(vis, false, sizeof(vis));
		if(n == 1) {
			printf("1\n");
			continue;
		} else {
			dfs(1, 0);
		}
	}
	return 0;
}

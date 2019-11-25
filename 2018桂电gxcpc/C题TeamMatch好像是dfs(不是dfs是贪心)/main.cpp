//题目要求x>=y>=z
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 32

using namespace std;

int n, m, rsmax;
int arr[MAXN], rs[MAXN];
bool vis[MAXN];

void dfs(int x) { //求arr[]的全排列
	if(x == n+1) {
		int count = 0;
		for(int i=1; i<=n-2; i+=3) {
			if(arr[rs[i]] >= arr[rs[i+1]] && arr[rs[i+1]] >= arr[rs[i+2]]) {
				int sum = 3*arr[rs[i]]+2*arr[rs[i+1]]+arr[rs[i+2]];
				if(sum >= m) count ++;
			}
		}
		if(count > rsmax) rsmax = count;
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i]) continue ;
		vis[i] = true;
		rs[x] = i;
		dfs(x+1);
		vis[i] = false;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		int tmax = 0;
		rsmax = 0;
		scanf("%d %d", &n, &m);
		memset(vis, false, n+10);
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		dfs(1);
		printf("%d\n", rsmax);
	}
	
	return 0;
}

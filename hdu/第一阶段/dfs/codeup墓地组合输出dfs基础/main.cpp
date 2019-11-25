#include <iostream>
#include <algorithm>
#include <math.h>
#define MAXN 30
using namespace std;

int n, r;

int arr[MAXN];
int rs[MAXN];
bool vis[MAXN];

void dfs(int x) {
	if(x == r+1) {
		for(int i=1, c=0; i<=r; i++) {
			if(c++) printf(" ");
			printf("%d", arr[rs[i]]);
		}
		printf("\n");
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i] && i>rs[x-1]) {
			rs[x] = i;
			vis[i] = true;
			dfs(x+1);
			vis[i] = false;
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &r); ) {
		for(int i=1; i<=n; i++) 
			arr[i] = i, rs[i] = i;
		dfs(1);
	}
	return 0;
}









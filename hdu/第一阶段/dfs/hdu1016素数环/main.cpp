#include <iostream>
#include <algorithm>
#include <math.h>
#define MAXN 30
using namespace std;

int n;
int rs[MAXN];
int arr[MAXN];
bool vis[MAXN];

bool is_ss(int x) {
	if(0==x || 1==x) return false;
	int t = sqrt(x);
	for(int i=2; i<=t; i++) {
		if(x%i == 0) return false;
	}
	return true;
}

void dfs(int x) {
	
	if(x == n+1) {
		int t = arr[rs[n]] + arr[rs[1]];
		if(is_ss(t)) {
			for(int i=1, c=0; i<=n; i++) {
				if(c++) printf(" ");
				printf("%d", arr[rs[i]]);
			}
			printf("\n");
		}
		return ;
	}

	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			int t = arr[rs[x-1]] + arr[i];
			if(!is_ss(t)) continue ;
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
	int count = 1;
	for( ; EOF != scanf("%d", &n); ) {
		printf("Case %d:\n", count++);
		for(int i=1; i<=n; i++) 
			arr[i] = i;
		vis[1] = true;
		rs[1] = 1;
		dfs(2);
		printf("\n");
	}
	
	return 0;
}









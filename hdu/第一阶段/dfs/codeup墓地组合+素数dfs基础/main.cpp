#include <iostream>
#include <algorithm>
#include <math.h>
#define MAXN 30
using namespace std;

int n, m, cnt;
int arr[MAXN];
bool vis[MAXN];
int rs[MAXN];

bool is_ss(int x) {
	if(x==1 || x==0) return false;
	else {
		int t = sqrt(x);
		for(int i=2; i<=t; i++) {
			if(x%i == 0) return false;
		}
		return true;
	}
}

void dfs(int x) {
	
	if(x == m+1) {
		int sum = 0;
		for(int i=1; i<=m; i++)
			sum += arr[rs[i]];
		if(is_ss(sum)) {
//			for(int i=1; i<=m; i++)
//				printf("%d,", arr[rs[i]]);
//			printf("\n");
			cnt ++;
		}
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
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i), rs[i] = i;
		dfs(1);
	//	printf("cnt:%d\n", cnt);
		printf("%d\n", cnt);
	}
	return 0;
}









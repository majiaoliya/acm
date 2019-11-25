#include <iostream>
#define MAXN 12
using namespace std;

int n;
int arr[MAXN];
bool vis[MAXN];

void dfs(int x) {
	if(x >= n+1) {
		for(int i=1, c=0; i<=n; i++) {
			if(c++) printf(" ");
			printf("%d", arr[i]);
		}
		printf("\n");
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			arr[x] = i;
			vis[i] = true;
			dfs(x+1);
			vis[i] = false;
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &n);
	dfs(1);
	return 0;
}

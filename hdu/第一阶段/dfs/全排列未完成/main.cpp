#include <iostream>
using namespace std;

int n; 
int p[10];
bool vis[10];
void dfs(int x) {
	if(x == n+1) {
		for(int i=1; i<=n; i++) {
			printf("%d,", p[i]);
		}
		printf("\n");
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			p[x] = i;
			vis[i] = true;
			dfs(x+1);
			vis[i] = false;
		}
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}

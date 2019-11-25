#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define MAXN 1000005
using namespace std;

int n, m, x;
bool vis[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int k=1; k<=m; k++) {
			scanf("%d", &x);
			vis[x] = true;
		}
	scanf("%d", &x);
	printf("%s\n", vis[x] ? "true" : "false");
	return 0;
}

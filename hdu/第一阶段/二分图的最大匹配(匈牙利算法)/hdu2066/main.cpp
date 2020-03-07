#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 510
using namespace std;

int m, nb, ng;
bool mtx[MAXN][MAXN];
bool vis[MAXN];
int nxt[MAXN];

void init() {
	memset(mtx, false, sizeof(mtx));
	memset(vis, false, sizeof(vis));
	memset(nxt, false, sizeof(nxt));
}

bool find(int x) { //红娘一般的匈牙利算法
	for(int i=1; i<=nb; i++) {
		if(mtx[x][i] && !vis[i]) {
			vis[i] = true;
			if(nxt[i]==0 || find(nxt[i])) {
				nxt[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d %d", &m, &nb, &ng); ) {
		if(0 == m) break;
		init();
		
		for(int i=1; i<=m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			mtx[x][y] = mtx[y][x] = true;
		}
		int sum = 0;
		for(int i=1; i<=nb; i++) {
			memset(vis, false, sizeof(vis));
			if(find(i)) sum ++;
		}
		printf("%d\n", sum);
	}
	
	return 0;
}

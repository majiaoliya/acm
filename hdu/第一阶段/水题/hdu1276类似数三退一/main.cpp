#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 5005
using namespace std;

bool vis[MAXN];
int n;

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d", &n);
		memset(vis, false, n+3);
		int m = 2, cnt = 0;
		while(cnt < n-3) {
			int tp = 0;
			for(int i=1; i<=n; i++) {
				if(vis[i]) continue;
				tp ++;
				if(tp == m) {
					tp = 0;
					vis[i] = true;
					cnt ++;
				}
			}
			m = m==2 ? 3 : 2;
		}
		for(int i=1, c=0; i<=n; i++) {
			if(vis[i]) continue;
			if(c++) printf(" ");
			printf("%d", i);
		}
		printf("\n");
	}
	return 0;
}

#include <iostream>
#include <string.h>
#define MAXN 10005

int t, n, m, arr[MAXN];
int hash[MAXN]; //p1+p3 = 2*p2 通过(p1+p3)/2获得p2的地址看在不在p1和p3之间

int max(int x, int y) { return x > y ? x : y; }

int main() {
	
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		m = 0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			hash[arr[i]] = i;
		}
		bool ok = false;
		for(int i=1; i<=n && !ok; i++) {
			for(int k=i+1; k<=n && !ok; k++) {
				int temp = (arr[i] + arr[k]);
				if(temp & 1) continue;
				if(hash[(temp>>1)]>i && hash[(temp>>1)]<k) 
					ok = true;
			}
		}
		printf("%s\n", ok ? "Y" : "N");
	}
	
	return 0;
}


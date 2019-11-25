#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n, t;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int x, cnt = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &x);
			if(x > 6000) cnt ++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}

#include <iostream>
#define MAXN 1005
using namespace std;

int n;

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n) && n) {
		int rs = 0, x;
		scanf("%d", &rs);
		for(int i=2; i<=n; i++) {
			scanf("%d", &x);
			rs ^= x;
		}
		printf("%d\n", rs);
	}
	return 0;
}

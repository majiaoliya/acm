#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 300005

using namespace std;

int n, m, arr[MAXN];

int get_min() {
	int ret = arr[1];
	for(int i=2; i<=n; i++)
		ret = min(ret, arr[i]);
	return ret;
}

int main() {
	freopen("test", "r", stdin);
	while(EOF != scanf("%d %d", &n, &m)) {
		memset(arr, false, sizeof(arr));
		int x;
		while(m--) {
			scanf("%d", &x);
			arr[x] ++;
		}
		printf("%d\n", get_min());
	}
	return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 300005

int n, q, arr[MAXN];

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &n);
	int ans = 0;
	for(int i=1; i<=n; i++) {
		scanf("%d", arr+i);
		for(int k=1; k<i; k++) {
			if(arr[k] > arr[i]) ans ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}


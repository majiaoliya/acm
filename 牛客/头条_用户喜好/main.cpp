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
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	scanf("%d", &q);
	while(q--) {
		int L, R, val, cnt = 0;
		scanf("%d %d %d", &L, &R, &val);
		for(int i=L; i<=R; i++)
			if(val == arr[i]) cnt ++;
		printf("%d\n", cnt);
	}
	return 0;
}


#include <bits/stdc++.h>

#define random(x) ( rand() % x)

int main(void) {
	freopen("test", "w", stdout);
	int t = 100;
	printf("%d\n", t);
	int inf = 1e9 + 7;
	for(int i=1; i<=t; i++)
		printf("%d %d\n", random(inf), random(inf));
	return 0;
}

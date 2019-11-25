#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 10005
using namespace std;

int w[MAXN], p[MAXN], dp[MAXN][MAXN], n, v, t;

int main()
{
	freopen("test", "w", stdout);
	int t = 10;
	int n = 10000, v = 10000;
	printf("%d\n", t);
	while(t--) {
		printf("%d %d\n", n, v);
		for(int i=0; i<n; i++) {
			if(i) printf(" ");
			printf("%d", i);
		}
		printf("\n");
		for(int i=0; i<n; i++) {
			if(i) printf(" ");
			printf("%d", i);
		}
		printf("\n");
	}
	return 0;
}




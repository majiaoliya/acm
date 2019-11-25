#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#define MAXN 50
using namespace std;

int n, t, arr[MAXN], tmax;

int main(void) {
	freopen("test", "r", stdin);
	arr[1] = arr[2] = 1;
	tmax = 1;
	for(scanf("%d", &t); t--; ) {
		scanf("%d", &n);
		if(n == 1 || n == 2) { printf("1\n"); continue; }
		if(n <= tmax) {
			printf("%d\n", arr[n]);
		} else {
			for(int i=tmax+1; i<=n; i++)
				arr[i] = arr[i-2] + arr[i-1];
			printf("%d\n", arr[n]);
		}
		tmax = max(n, tmax);
	}
	return 0;
}

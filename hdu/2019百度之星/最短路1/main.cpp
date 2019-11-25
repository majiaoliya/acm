#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
#define min(x,y) ( x > y ? y : x )
#define ll long long int
#define MAXN 10005
using namespace std;

int t, n;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		int sum;
		scanf("%d", &n);
		/**
		for(int i=2; i<=n; i++) {
			sum += i^(i-1);
			printf("%d^%d = %d ", i, (i-1), sum);
		}
		*/
		printf("%d\n", 1^n);
	}
	return 0;
}

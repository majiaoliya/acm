#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n;

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n); ) {
		int size = 0, stk[MAXN];
		while(n) {
			stk[size++] = (n&1);
			n >>= 1;
		}
		for(int i=size-1; i>=0; i--)
			printf("%d", stk[i]);
		printf("\n");
	}
	return 0;
}

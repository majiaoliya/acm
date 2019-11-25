#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n;

int getsum(int x, int rad) {
	int rs = 0;
	while(x) {
		rs += x%rad;
		x /= rad;
	}
	return rs;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; cin>>n && n; ) {
		bool ok = (getsum(n, 10)==getsum(n, 16) && getsum(n, 12)==getsum(n, 16));
		printf("%d %s\n", n, ok ? "is a Sky Number." : "is not a Sky Number.");
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define EPS .000001
using namespace std;

int t, n;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int lsm(int a, int b) { //返回a,b的最小公倍数
	int tgcd = gcd(a, b);
	return (a/tgcd*b);
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d", &n);	
		int a, b, x;
		for(int i=1; i<=n; i++) {
			scanf("%d", &x);
			if(i==1) { a = x; continue; }
			a = lsm(a, x);
		}
		printf("%d\n", a);
	}
	
	return 0;
}






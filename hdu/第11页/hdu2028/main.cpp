#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN ((int)5e5+10)
using namespace std;

int arr[MAXN], n;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lsm(int a, int b) {
	int gcd_ab = gcd(a, b);
	return a/gcd_ab*b;
}
int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n); ) {
		int rs, x, tmin;
		for(int i=1; i<=n && EOF!=scanf("%d", &x); i++) {
			if(i==1) rs = x, tmin = rs;
			else rs = gcd(rs, x), tmin = min(tmin, x);
		}
		printf("%d\n", lsm(tmin, rs));
	}
	return 0;
}

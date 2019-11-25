#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 10005
int n;
char str[MAXN];
int min(int a, int b) { return a < b ? a : b; }
int min(int a, int b, int c, int d) {
	int x = min(a, b), y = min(c, d);
	return min(x, y);
}

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%d\n%s", &n, str)) {
		int aa = 0, vv = 0, ii = 0, nn = 0;
		for(int i=0; i<n; i++) {
			if(str[i] == 'a') aa++;
			else if(str[i] == 'v') vv++;
			else if(str[i] == 'i') ii++;
			else if(str[i] == 'n') nn++;
		}
		int fz = aa*vv*ii*nn;
		int fm = n*n*n*n;
		int gcdab = __gcd(fz, fm);
		if(fz) printf("%d/%d\n", fz/gcdab, fm/gcdab);
		else printf("0/1\n");

	}
	return 0;
}


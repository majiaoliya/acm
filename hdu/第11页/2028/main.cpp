#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n;

int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }
int lmp(int a, int b) { return a/gcd(a,b)*b; }

int main(void) {
	freopen("test", "r", stdin);
	while(EOF != scanf("%d", &n)) {
		int lst, x, rs;
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			if(!i) {
				rs = lst = x;
				continue;
			}
			rs = lmp(rs, x);
		}
		printf("%d\n", rs);
	}
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n;

int main(void) {
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d", &n); ) {
		int rs = 0;
		while(n) {
			int t = n%10;
			rs = max(t, rs);
			n /= 10;
		}
		printf("%d\n", rs);
	}
	
	return 0;
}

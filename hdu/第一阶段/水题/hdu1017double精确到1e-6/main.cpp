#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define EPS .000001
using namespace std;

int n, m, rs, t;

void func() {
	rs = 0;
	for(int a=1; a<n; a++) {
		for(int b=a+1; b<n; b++) {
			if(double(a*a + b*b + m) / double(a*b) - (a*a + b*b + m) / (a*b) < EPS) { rs ++;  }
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		int cas = 0;
		while(EOF!=scanf("%d %d", &n, &m) && (n||m)) {
			func();
			printf("Case %d: %d\n", ++cas, rs);
		}
		if(t) printf("\n");
	}
	return 0;
}






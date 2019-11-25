#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	double n;
	int m;
	for( ; EOF != scanf("%lf %d", &n, &m); ) {
		float rs = 0;
		for( ; m--; ) {
			rs += n;
			n = sqrt(n);
		}
		printf("%.2lf\n", rs);
	}
	
	return 0;
}

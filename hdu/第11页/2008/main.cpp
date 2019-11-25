#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#define float double
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	int n;
	for( ; EOF != scanf("%d", &n), n!=0; ) {
		int a=0, b=0, c=0;
		for(int i=1; i<=n; i++) {
			double x;
			scanf("%lf", &x);
			if(x > 0.0000) c ++;
			else if(x == 0.0000) b ++;
			else a ++;
		}
		printf("%d %d %d\n", a, b, c);
	}
	
	return 0;
}

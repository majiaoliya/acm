#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	for(int n; EOF != scanf("%d", &n); ) {
		double rs = 0, tmax = 0, tmin = 0;
		for(int i=0; i<n; i++) {
			double x;
			scanf("%lf", &x);
			if(!i) tmax = x, tmin = x;
			else {
				if(x > tmax) tmax = x;
				if(x < tmin) tmin = x;
			}
			rs += x;
		}
		printf("%.2lf\n", (rs-tmax-tmin)/(n-2));
	}
	return 0;
}

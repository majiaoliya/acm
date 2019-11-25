#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>

#define PI 3.1415927

using namespace std;

float my_abs(float x) { return x > 0 ? x : -x; }

int main(void) {
	freopen("test", "r", stdin);
	
	double r;
	for( ; EOF != scanf("%lf", &r); ) {
		double v = 4*PI*r*r*r/3;
		printf("%.3lf\n", v);
	}	
	
	return 0;
}

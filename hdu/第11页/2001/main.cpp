#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <screen/screen.h>
using namespace std;

float my_abs(float x) { return x > 0 ? x : -x; }

int main(void) {
	freopen("test", "r", stdin);
	
	float x1, y1, x2, y2;
	for( ; EOF != scanf("%f %f %f %f", &x1, &y1, &x2, &y2); ) {
		float xx = my_abs(x1-x2); xx *= xx;
		float yy = my_abs(y1-y2); yy *= yy;
		float rs = sqrt(xx + yy);
		printf("%.2f\n", rs);
	}
	return 0;
}

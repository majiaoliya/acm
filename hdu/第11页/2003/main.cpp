#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#define float double
using namespace std;

float my_abs(float x) { return x > 0 ? x : -x; }

int main(void) {
	freopen("test", "r", stdin);
	float num;
	for( ; EOF != scanf("%lf", &num); ) {
		printf("%.2lf\n", my_abs(num));
	}

	return 0;
}

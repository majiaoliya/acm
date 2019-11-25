#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	freopen("test", "r", stdin);
	double mon, year, rate;
	scanf("%lf %lf %lf", &mon, &year, &rate);
	double rs = mon * pow((1+rate), year) - mon;
	printf("interest = %.2lf\n", rs);
	return 0;
}


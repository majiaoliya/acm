#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	freopen("test", "r", stdin);
	
	long long int a, n;
	scanf("%lld %lld", &a, &n);
	long long int ta = a;
	for(int i=1; i<n; i++) {
		ta *= 10;
		ta += a;
	}
	long long int sum = ta;
	for(int i=1; i<n; i++) {
		ta /= 10;
		sum += ta;
	}
	printf("%lld\n", sum);
	
	return 0;
}

























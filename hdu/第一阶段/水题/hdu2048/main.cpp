#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	float son, par;
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%f", &son);
		printf("%.2f%%\n", (1/son)*100);
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
using namespace std;


int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		double a, b, c;
		scanf("%lf %lf %lf", &a, &b, &c);
		if((a+b>c) && (a+c>b) && (c+b>a)) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 512
using namespace std;

int main()
{
	freopen("test", "r", stdin);
	
	double x, rs = 0;
	scanf("%lf", &x);
	rs = 1;
	double jieche = 1; //第i项的阶乘
	double mi = x;
	bool tag = true;
	
	for(int i=1; tag; i++) {
		double t = mi / jieche;
		if(t < 0.00001) tag = false;
		rs += t;
		mi *= x;
		jieche *= i+1;
	}
	printf("%.4lf\n", rs);
	
	return 0;
}


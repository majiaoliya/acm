#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#define MAXN 16
using namespace std;

int n;

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &n);
	int fz = 1, fm = 1;
	double sum = 0;
	for(int i=1; i<=n; i++) {
		if(i%2 == 0) fz = -1;
		else fz = 1;
		sum += (fz*1.)/(fm*1.);
		fm += 3;
	}
	printf("sum = %.3lf\n", sum);
	return 0;
}


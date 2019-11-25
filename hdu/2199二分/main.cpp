
#include <iostream>
#include <math.h>
using namespace std;

double calc(double x) { return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6; }

int main(void) {
	freopen("test", "r", stdin);
	int t, y;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &y);
		double lef = 0.0, rig = 100.0, mid, rs = -1;
		if(calc(lef)>y || calc(rig)<y) {
			printf("No solution!\n");
			continue;
		}
		while(true) {
			mid = (lef+rig) / 2;
			if( (fabs(calc(mid)-y) <= 1e-5) ) break;
			if(calc(mid) > y)
				rig = mid-1;
			else
				lef = mid+1;
		}
		printf("%.4lf\n", mid);
	}
	
	return 0;
}


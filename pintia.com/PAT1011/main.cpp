#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double mtx[4][4];

int main() {
	freopen("test", "r", stdin);
	
	int rs[4] = {0};
	double ji = 0;
	for(int i=1; i<=3; i++) {
		double tmax;
		scanf("%lf", &tmax);
		rs[i] = 'W';
		for(int k=2; k<=3; k++) {
			double x;
			scanf("%lf", &x);
			if(tmax < x) {
				tmax = x;
				rs[i] = (k==2 ? 'T' : 'L');
			}
		}
		if(i==1) ji = tmax;
		else ji *= tmax;
	}
	double rssum = (ji*.65 - 1) * 2;
	printf("%c %c %c %.2lf\n", rs[1], rs[2], rs[3], rssum);	
	
	return 0;
}

























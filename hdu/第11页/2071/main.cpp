#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 55
#define ll long long int
using namespace std;

int n, t;
double m;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		double x;
		for(int i=0; i<n; i++) {
			scanf("%lf", &x);
			if(!i) {
				m = x;
				continue;
			}
			m = max(x, m);
		}
		printf("%.2lf\n", m);
	}
	return 0;
}

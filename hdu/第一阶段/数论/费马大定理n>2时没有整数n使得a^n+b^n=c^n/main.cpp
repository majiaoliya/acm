#include <iostream>
#include <algorithm>
#include <math.h>
#define ll long long int
using namespace std;

ll a, n, t;

int main(void) {
	freopen("test", "r", stdin);
	cin >> t;
	while(t--) {
		cin >> n >> a;
		if(n == 1) {
			printf("%d %d\n", a+1, a+a+1);
		} else if(n == 2) {
			printf("%d %d\n", a+1, (int)sqrt(a*a+(a+1)*(a+1)));
		} else {
			printf("-1 -1\n");
		}
	}
	return 0;
}

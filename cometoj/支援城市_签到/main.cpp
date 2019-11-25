#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long int
const int MAXN = 100005;
ll n, arr[MAXN];
/**
int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%lld", &n)) {
		int c = 0;
		for(int i=1; i<=n; i++)
			scanf("%lld", arr+i);
		for(int i=1; i<=n; i++) {
			ll sum = 0;
			for(int k=1; k<=n; k++) {
				int sub = arr[i] - arr[k];
				sum += sub*sub;
			}
			if(c++) printf(" ");
			printf("%lld", sum);
		}
		printf("\n");
	}
	return 0;
}
*/

// (w1-w1)^2 + (w2-w1)^2 + (w3-w1)^2 + (w4-w1)^2 + 
// (w1-w2)^2 + (w2-w2)^2 + (w3-w2)^2 + (w4-w2)^2 +
// (w1-w3)^2 + (w2-w3)^2 + (w3-w3)^2 + (w4-w3)^2 +
// (w1-w4)^2 + (w2-w4)^2 + (w3-w4)^2 + (w4-w4)^2 +

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%lld", &n)) {
		for(int i=1; i<=n; i++)
			scanf("%lld", arr+i);
		ll rs = 0, c = 0;
		for(int i=1; i<=n; i++) {
			ll sum = 0;
			for(int k=i+1; k<=n; k++) {
				sum += (arr[i]-arr[k]) * (arr[i]-arr[k]);
			}
			if(c++) printf(" ");
			printf("%lld", sum<<1);
		}
		printf("\n");
	}
	return 0;
}

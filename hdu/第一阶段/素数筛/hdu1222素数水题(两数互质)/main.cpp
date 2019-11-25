#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define MAXN 1000000005
#define ll long long int
using namespace std;

ll t, x, y;

ll gcd(ll a, ll b) {
	return (b>0) ? gcd(b, a%b) : a;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%lld", &t);
	for( ; t--; ) {
		scanf("%lld %lld", &x, &y);
		if(x == 1) printf("NO\n");
		else if(gcd(x, y) != 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int 
using namespace std;
ll n, k;

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%lld", &n); ) {
		ll rs = (n*(n-1)) + n;
		printf("%lld\n", rs);
	}
	return 0;
}

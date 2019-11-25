#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 300005
#include <map>
#define ll long long int
#define max(x, y) ( x > y ? x : y )
#define min(x, y) ( x < y ? x : y )
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

ll n, m;

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%lld", &n)) {
		ll minx, miny, maxx, maxy;
		for(ll i=1, x, y; i<=n; i++) {
			scanf("%lld %lld", &x, &y);
			if(i == 1) {
				minx = maxx = x;
				miny = maxy = y;
			} else {
				minx = min(minx, x), miny = min(miny, y);
				maxx = max(maxx, x), maxy = max(maxy, y);
			}
		}
		ll w = maxx - minx, h = maxy - miny;
		printf("%lld\n", max(w,h)*max(w,h));
	}
	
	return 0;
}




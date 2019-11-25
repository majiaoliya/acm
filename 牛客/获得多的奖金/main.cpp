#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 200005
#include <map>
#include <unordered_set>
#define ll long long int
#define max(x, y) ( x > y ? x : y )
#define min(x, y) ( x < y ? x : y )
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

ll n, arr[MAXN];

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%lld", &n)) {
		for(int i=1; i<=n; i++)
			scanf("%lld", arr+i);
		int lef = 0, rig = n+1;
		ll lsum = 0, rsum = 0, rs = 0;
		while(lef < rig) {
			if(lsum == rsum) rs = lsum;
			if(lsum <= rsum) 
				lsum += arr[++lef];
			else
				rsum += arr[--rig];
		}
		printf("%lld", rs);
	}
	return 0;
}




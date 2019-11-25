#include <iostream>
#include <algorithm>
#include <math.h>
#define MAXN 1000005
#define ll long long int
#define eps 0.000001
using namespace std;

ll arr[MAXN], n, m, sum;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%lld %lld", &n, &m);
	
	for(int i=1; i<=n; i++) scanf("%lld", arr+i), sum += arr[i];
	sort(arr+1, arr+1+n);
	ll lef = 0, rig = sum, mid, ans = -1;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		ll mm = 0;
		for(int i=1; i<=n; i++) {
			if(arr[i] > mid) mm += arr[i]-mid;
		}
		if(mm >= m) ans = mid, lef = mid + 1;
		else rig = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}

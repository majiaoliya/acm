#include <iostream>
#include <algorithm>
#define MAXN 1000005
#define ll long long int
using namespace std;

ll n, m; //求arr[]中有多少对 x+y == m (n<=1e5, x, y <= 2^31-1)
ll arr[MAXN];

int binsearch(ll val) {
	int lef = 0, rig = n-1, mid;
	while(lef <= rig) {
//		mid = (lef+rig) >> 1;
		mid = lef + (rig-lef)/2;
		if(val < arr[mid])
			rig = mid - 1;
		else if(val > arr[mid])
			lef = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main(void) {
	freopen("test", "r", stdin);
	ll t;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld", &n, &m);
		for(int i=0; i<n; i++)
			scanf("%lld", arr+i);
		sort(arr, arr+n);
		ll cnt = 0;
		for(int i=0; i<n; i++) {
			if(arr[i]>m || arr[i]==arr[i-1]) continue;
			else if(binsearch(m-arr[i]) != -1) cnt ++;
		}
		printf("%lld\n", cnt);
	}

	return 0;
}

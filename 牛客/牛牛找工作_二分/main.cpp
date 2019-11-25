#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 300005
#include <map>
#define ll long long int
#define max(x, y) ( x > y ? x : y )

using namespace std;

ll n, m;
struct Node {
	ll hard, val;
} arr[MAXN];
map<ll, ll> mp;

int cmp(Node& x, Node& y) { return x.hard < y.hard; }
// 这个二分有很大的问题
ll binsearch(ll val) {
	ll mid = -1, lef = 0, rig = n-1;
	while(lef < rig) {
		mid = (lef + rig + 1) >> 1;
		if(arr[mid].hard <= val) lef = mid;
		else rig = mid - 1;
	}
	if(arr[lef].hard > val) return -1;
	printf("%lld %lld", val, arr[lef].hard);
	return arr[lef].hard;
}

int main() {
	freopen("test", "r", stdin);
	
	while(~scanf("%lld %lld", &n, &m)) {
		mp.clear();
		ll tmax = 0;
		for(int i=0; i<n; i++) {
			scanf("%lld %lld", &arr[i].hard, &arr[i].val);
		}
		sort(arr, arr+n, cmp);
		tmax = arr[0].val;
		mp[arr[0].hard] = tmax;
		for(int i=1; i<n; i++) {
			tmax = max(tmax, arr[i].val);
			mp[arr[i].hard] = tmax;
		}
		ll x;
		while(m--) {
			scanf("%lld", &x);
			map<ll, ll>::iterator it = mp.lower_bound(x);
			if(it == mp.end()) it --;
			else if(it->first > x) it --;
			printf("%lld\n", it->second);
//			printf("x:%lld idx:%lld\n", x, idx);
		}
	}
	
	/**
	int temp[] = {
		1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 9, 9, 9
	};
	for(int i=0; i<=12; i++)
		printf("[%d %lld] ", i, binsearch(i, temp, 13));
	*/
	return 0;
}




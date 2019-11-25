#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long int
#define MAXN ((int)(2e5+7))

ll n, arr[MAXN], c, ans;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%lld %lld", &n, &c);
	for(int i=0; i<n; i++)
		scanf("%lld", arr+i);
	sort(arr, arr+n);
	for(int i=0; i<n; i++) {
		int lef = i, rig = n-1, mid, id1 = -1, id2 = -1;
		ll key = arr[i] + c;
		while(lef <= rig) { //找最左边的key
			mid = (lef + rig) >> 1;
			if(arr[mid] >= key) {
				if(arr[mid] == key) id1 = mid;
				rig = mid - 1;
			} else 
				lef = mid + 1;
		}
		if(-1 == id1) continue ;
		lef = i, rig = n-1;
		while(lef <= rig) { //找最右边的key
			mid = (lef + rig) >> 1;
			if(arr[mid] <= key) {
				if(arr[mid] == key) id2 = mid;
				lef = mid + 1;
			} else 
				rig = mid - 1;
		}
		if(-1 == id2) continue ;
//		cout << id1 << ", " << id2 << endl;
		ans += id2 - id1 +1;
	}
	printf("%lld\n", ans);
	return 0;
}




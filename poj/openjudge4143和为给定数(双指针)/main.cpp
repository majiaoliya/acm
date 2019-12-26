#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

ll n, m, T, arr[MAXN];

ll binsearch(ll key) {
	ll lef = 1, rig = n, mid;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(arr[mid] == key) return mid;
		else if(arr[mid] > key) rig = mid - 1;
		else lef = mid + 1;
	}
	return -1;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i];
	cin >> m;
	sort(arr+1, arr+1+n);
	/** nlogn 枚举每个数字二分key前提arr[]无重复
	for(int i=1; i<=n; i++) {
		ll key = m - arr[i];
		ll id = binsearch(key);
		if(-1!=id && id!=i) {
			cout << min(arr[i],key) << " " << max(key,arr[i]) << endl;
			goto finish;
		}
	}
	*/
	//双指针 O(n)
	ll lef = 1, rig = n;
	while(lef < rig) {
		if(arr[lef]+arr[rig] == m) {
			cout << arr[lef] << " " << arr[rig] << endl;
			goto finish;
		} else if(arr[lef]+arr[rig] < m) lef ++;
		else rig --;
	}
	cout << "No" << endl;


finish: ;

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



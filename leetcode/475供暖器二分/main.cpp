#define debug
#ifdef debug
#include <iostream>
#endif

#include <vector>
#include <algorithm>
using namespace std;
#include <set>
#define ll long long int
#define abs(x) (x > 0 ? x : -x)
class Solution {
public:
	int n;

	ll binsearch(vector<int>& v2, int key) { //二分找到第一个小于等于key的值
		ll lef = 0, rig = v2.size()-1, mid, ret = -1;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(key <= v2[mid]) ret = mid, rig = mid - 1;
			else lef = mid + 1;
		}
		return ret;
	}

    int findRadius(vector<int>& v1, vector<int>& v2) {
		n = v1.size();
		ll tmax = -1;
		sort(v2.begin(), v2.end());
		for(int i=0; i<n; i++) {
			int key = v1[i];
			int idx = lower_bound(v2.begin(), v2.end(), key) - v2.begin();
			
		}
	//	乱乱的	
	//	for(int i=0; i<n; i++) {
	//		int key = v1[i];
	//		int idx = std::lower_bound(v2.begin(), v2.end(), key) - v2.begin();
	//		if(v2[idx] == key) tmax = max(tmax, (ll)0);
	//		else if(idx-1>=0) {
	//			ll l = abs(v2[idx-1] - i), r = abs(v2[idx] - i);
	//			ll tmin = min(l, r);
	//			tmax = max(tmax, tmin);
	//		} else {
	//			tmax = max(tmax, (ll)abs(v2[idx]-i));
	//		}
	//	}
		return tmax;
	}
};

#ifdef debug
int main(void) {
	vector<int> v1 = { 1,2,3,4 };
	vector<int> v2 = { 1,4 };
	Solution s;
	cout << s.findRadius(v1, v2) << endl;
	return 0;
}
#endif

#define ll long long int
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

#include <algorithm>
#define ll long long int
class Solution {
public:
	bool check(vector<int>& arr, int mid, int m) {
		ll sum = 0;
		for(int i=0; i<(int)arr.size(); i++) {
			sum += (arr[i] / mid);
			if(arr[i] % mid) sum ++;
		}
		return sum <= m;
	}
    int minEatingSpeed(vector<int>& arr, int m) {
		ll lef = 1, rig = pow(10, 9), mid, ret = 0;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(check(arr, mid, m)) ret = mid, rig = mid - 1;
			else lef = mid + 1;
		}
		return ret;
	}
};

#define debug
#ifdef debug
int main(void) {
	vector<int> va = {3,6,7,11};
	vector<int> vb = {30,11,23,4,20};
	vector<int> vc = {30,11,23,4,20};
	Solution s;
	cout << s.minEatingSpeed(va, 8) << endl;
	cout << s.minEatingSpeed(vb, 5) << endl;
	cout << s.minEatingSpeed(vc, 6) << endl;
	return 0;
}
#endif

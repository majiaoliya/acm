#define ll long long int
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int tar) {
#ifdef debug
		return lower_bound(nums.begin(), nums.end(), tar) - nums.begin();
#endif
		int lef = 0, rig = nums.size()-1, mid = -1;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(nums[mid] == tar) return mid;
			else if(nums[mid] < tar) lef = mid+1;
			else rig = mid-1;
		}
		return lef;
	}
};
#ifdef debug
int main(void) {
	vector<int> v = { 1,3,5,6 };
	int m = 2;
	Solution s;
	cout << s.searchInsert(v, 5) << endl;
	cout << s.searchInsert(v, 2) << endl;
	cout << s.searchInsert(v, 4) << endl;
	cout << s.searchInsert(v, 0) << endl;
	return 0;
}
#endif

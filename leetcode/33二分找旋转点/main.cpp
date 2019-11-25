#define ll long long int
#include <vector>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int tar) {
		if(nums.empty()) return -1;
		int lef = 0, rig = nums.size()-1, mid, idx = -1;
		if(nums[lef] > nums[rig]) {
			while(lef <= rig) {
				mid = (lef + rig) >> 1;
	//			printf("mid:[%d %d lef:[%d %d] rig:[%d %d]\n", mid, nums[mid], lef, nums[lef], rig, nums[rig]);
				if(nums[mid] > nums[mid+1]) {
					idx = mid;
					break;
				} else if(nums[mid] < nums[mid-1]) {
					idx = mid - 1;
					break;
				}
				if(nums[mid] > nums[lef]) lef = mid + 1;
				else if(nums[mid] < nums[rig]) rig = mid - 1;
			}
		}
		lef = 0, rig = idx;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(nums[mid] == tar) return mid;
			else if(nums[mid] > tar) rig = mid - 1;
			else lef = mid + 1;
		}
		lef = idx+1, rig = nums.size()-1;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(nums[mid] == tar) return mid;
			else if(nums[mid] > tar) rig = mid - 1;
			else lef = mid + 1;
		}
		printf("pointer:%d\n", idx);
		return -1;
    }
};
#define debug
#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
//	vector<int> nums = { 4,5,6,7,0,1,2 };
	Solution s;
//	int rs = s.search(nums, 0);
	//cout << rs << endl;
	//nums = { 4,5,6,7,8, 9,0,1,2 };
	//rs = s.search(nums, 0);
	//cout << rs << endl;
	vector<int> nums = {8,9,2,3,4};
	int rs = s.search(nums, 9);
	cout << rs << endl;
	return 0;
}
#endif

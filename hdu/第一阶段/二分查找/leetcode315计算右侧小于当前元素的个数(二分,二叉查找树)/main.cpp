#define ll long long int
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
#define debug
class Solution {
public:
    
	//二分+排序
	//O(n)扫一遍nums, 维护一个有序数组arr, 在arr上二分nums[i]的位置
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0), arr;
		for(int i=n-1; i>=0; i--) {
			vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), nums[i]);
			ans[i] = pos-arr.begin();
			arr.insert(pos, nums[i]);
		}
        return ans;
    }
};

#ifdef debug
int main(void) {
	vector<int> nums = { 5, 2, 6, 1 };
	Solution s;
	vector<int> ans = s.countSmaller(nums);
	for(auto x : ans)
		cout << x << " ";
	cout << endl;
	return 0;
}
#endif




#include <iostream>
#include <vector>
using namespace std;
//
//给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数
//
//'^'运算满足交换律

class Solution {
public:
    int missingNumber(vector<int>& nums) { //
		int ans = nums.size();
        for(int i=0; i<(int)nums.size(); i++)
			ans = ans ^ nums[i] ^ i;
    	return ans;
	}
} ;

int main(void) {
	vector<int> arr = {3,0,1};
	Solution s;
	cout << s.missingNumber(arr) << endl;
	return 0;
}

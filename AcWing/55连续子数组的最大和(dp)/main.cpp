#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int sum = 0, ret = 0;
		ret = -999999999;
		for(int i=0; i<n; i++) {
			if(sum < 0) {
				sum = nums[i];
			} else {
				sum += nums[i];
			}
			ret = max(ret, sum);
		}
		return ret;
    }
};

#ifdef debug
int main(void) {
	vector<int> v = {1, -2, 3, 10, -4, 7, 2, -5};
	Solution s;
	int tmp = 0;
	printf("%d\n", s.maxSubArray(v));
	printf("min:%d   max:%d\n", (1<<31), (1<<31)-1);
	return 0;
}
#endif

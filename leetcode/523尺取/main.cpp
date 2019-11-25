#include <stack>
#include <string.h>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#define debug
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int kk) {
		bool ret = false;
		for(int i=0, sum=0, n=v.size(); i<n; i++) {
			if(!kk) sum = (sum + v[i]) % kk;
		}
		return ret;
    }
};

#ifdef debug
int main(void) {
	vector<int> nums = { 23,2,4,6,7 };
	Solution s;
	printf("%d\n", s.checkSubarraySum(nums ,6));
	return 0;
}
#endif

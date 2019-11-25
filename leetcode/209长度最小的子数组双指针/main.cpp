#define ll long long int
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    双指针O(N)
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, k = 0, n = nums.size()-1, sum = 0, rs = n+5;
        while(i<=n) {
            while(k<=n && sum<=s) sum += nums[k++];
            if(sum > s) {
                rs = min(rs, k-i-1);
            } else if(sum == s) 
                rs = min(rs, k-i);
            sum -= nums[i++];
        }
        return rs > n ? 0 : rs;
    }
   
};

#define debug
#ifdef debug
int sumit(vector<int>& v, int lef, int rig) {
	int sum = 0;
	for(int i=lef; i<=rig; i++) sum += v[i];
	return sum;
}
int main(void) {
	Solution s;
	vector<int> v = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
	printf("%d\n", s.minSubArrayLen(80, v));
	return 0;
}
#endif



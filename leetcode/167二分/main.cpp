#define ll long long int
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int tar) {
        int lef, rig, n = v.size();
		lef = 0, rig = n-1;
		while(lef < rig) {
			int sum = v[lef] + v[rig];
			if(sum == tar) return {lef+1, rig+1};
			else if(sum < tar) lef ++;
			else rig --;
		}
		return {-1, -1};
    }
};
#define debug
#ifdef debug
int main(void) {
	vector<int> v = { 2, 7, 11, 15 };
	int m = 2;
	Solution s;
	cout << s.twoSum(v, 9).at(0) << "," << s.twoSum(v, 9).at(1) << endl;
	return 0;
}
#endif

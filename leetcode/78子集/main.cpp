#define ll long long int
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int n;


typedef vector<vector<int> > vvi;

class Solution {
public:
    vvi ret;
//    vector<vector<int>> subsets(vector<int>& nums) {
//        n = nums.size();
//        vector<int> arr;
//        dfs(0, nums, arr);
//        return ret;
//    }
	//二进制优化
	vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
		vector<int> tmp;
		for(int i=0; i<pow(2, n); i++) {
			int idx = 0, j = i;
			while(j) {
				if(j & 1) tmp.push_back(nums[idx]);
				j >>= 1;
				idx ++;
			}
			ret.push_back(tmp);
			tmp.clear();
		}
//		ret.push_back({});
		return ret;
    }
    
    void dfs(int x, vector<int>& nums, vector<int> arr) {
		if(x >= n) return ;
		arr.push_back(nums[x]);
		dfs(x+1, nums, arr);
		ret.push_back(arr);
		arr.pop_back();
		dfs(x+1, nums, arr);
	}
};

#define debug
#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n)) {
		vector<int> v;
		for(int i=0; i<n; i++) {
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		Solution s;
		vvi ans = s.subsets(v);
		for(int k=0; k<ans.size(); k++) {
			for(int i=0; i<ans[k].size(); i++)
				printf("%d ", ans[k][i]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
#endif



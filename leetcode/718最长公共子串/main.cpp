#define ll long long int
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#include <algorithm>

class Solution {
public:
    int findLength(vector<int>& va, vector<int>& vb) {
		int maxn = max(va.size(), vb.size());
		vector<vector<int> > dp(maxn+1, vector<int>(maxn+1, 0));
		int ret = 0;
		for(int i=0; i<(int)va.size(); i++) {
			for(int k=0; k<(int)vb.size(); k++) {
				if(va[i] == vb[k]) dp[i+1][k+1] = dp[i][k] + 1;
				else dp[i+1][k+1] = 0;
				ret = max(dp[i+1][k+1], ret);
			}
		}
		return ret;
    }
};

#define debug
#ifdef debug
int main(void) {
	vector<int> va = {1,2,3,2,1};
	vector<int> vb = {3,2,1,4,7};
	Solution s;
	cout << s.findLength(va, vb) << endl;
	return 0;
}
#endif

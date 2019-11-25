#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug

class Solution {
public:
    int getMaxValue(vector<vector<int>>& grid) {
    	int row = grid.size(), col = grid[0].size();
		int dp[row+3][col+3] = { 0 };
		memset(dp, false, sizeof(dp));
		for(int i=row-1; i>=0; i--) {
			for(int k=col-1; k>=0; k--) {
				dp[i][k] = max(grid[i][k]+dp[i+1][k], grid[i][k]+dp[i][k+1]);
			}
		}
		return dp[0][0];
	}
};

#ifdef debug
int main(void) {
//	vector<int> v = { 2, 3, 1 };
	vector<int> v = { 1 };
	vector<int> v2 = { 1, 7, 1 };
	vector<int> v3 = { 4, 6, 1 };
	vector<vector<int> > mtx = {v};
	Solution s;
	printf("%d\n", s.getMaxValue(mtx));
	return 0;
}
#endif

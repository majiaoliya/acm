#define ll long long int
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#define abs(x) (x > 0 ? x : -x)
#define MAXN (302)
using namespace std;
#define debug
typedef vector<vector<int> > vvi;

bool cmp(vector<int>&x, vector<int>& y) {
	return x[0] < y[0];
}

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& vv) {
		vvi ret;
		if(vv.empty()) return ret;
		sort(vv.begin(), vv.end(), cmp);
		int n = (int)vv.size();
		for(int i=0; i<n; i++) {
			if(!i) {
				ret.push_back(vv[i]);
			} else {
				vector<int>& lst = ret.back();
				if(lst[1] >= vv[i][0]) {
					lst[1] = max(lst[1], vv[i][1]);
				} else {
					ret.push_back(vv[i]);
				}
			}
		}
		return ret;
    }
};
#define debug
#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	Solution s;
	vvi vv = {
		{1,3},{2,6},{8,10},{15,18}
	};
	vvi ret = s.merge(vv);
	for(int i=0; i<(int)ret.size(); i++) {
		printf("%d %d\n", ret[i][0], ret[i][1]);
	}
	return 0;
}
#endif

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
    vector<vector<int> > insert(vector<vector<int> >& vv, vector<int>& x) {
		vvi ret;
		if(vv.empty() && x.empty()) return ret;
        if(vv.empty() && !x.empty()) return {x};
		int lef = 0, rig = vv.size()-1, mid, idx = -1;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(vv[mid][0] <= x[0]) idx = mid, lef = mid + 1;
			else rig = mid - 1;
		}
		if(idx == -1) ret.push_back(x);
		int i = 0, n = idx==(int)vv.size() ? vv.size()-1 : idx;
		for( ; i<=n; i++) {
			if(!i && ret.empty()) {
				ret.push_back(vv[i]);
			} else {
				vector<int>& lst = ret.back();
				if(lst[1] >= vv[i][0]) lst[1] = max(vv[i][1], lst[1]);
				else ret.push_back(vv[i]);
			}
		}
		if(idx != (int)vv.size()) {
			vector<int>& lst = ret.back();
			if(lst[1] >= x[0]) lst[1] = max(lst[1], x[1]);
			else ret.push_back(x);
		}
		n = vv.size();
		for( ; i<n; i++) {
			if(!i && ret.empty()) {
				ret.push_back(vv[i]);
			} else {
				vector<int>& lst = ret.back();
				if(lst[1] >= vv[i][0]) lst[1] = max(vv[i][1], lst[1]);
				else ret.push_back(vv[i]);
			}
		}
		if(idx == (int)vv.size()) {
			vector<int>& lst = ret.back();
			if(lst[1] >= x[0]) lst[1] = max(lst[1], x[1]);
			else ret.push_back(x);
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
		{1,3},{6,9}
	};
	vector<int> x = {
		{2, 5}
	};
	vvi ret = s.insert(vv, x);
	for(int i=0; i<(int)ret.size(); i++) {
		printf("%d %d\n", ret[i][0], ret[i][1]);
	}
	return 0;
}
#endif


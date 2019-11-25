#define ll long long int
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef vector<vector<int> > Mtx;

#define ll long long int
#define BACK(x) (mtx[x].back())
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mtx, int key) {
        if(mtx.empty() || mtx[0].empty()) return false;
		int lef = 0, rig = mtx.size()-1, mid, idx = -1;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(BACK(mid) >= key) idx = mid, rig = mid - 1;
			else lef = mid + 1;
		}
        // cout << "index:" << idx << endl;
        if(idx < 0) return false;
		lef = 0, rig = mtx[idx].size()-1;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(mtx[idx][mid] == key) return true;
			else if(mtx[idx][mid] < key) lef = mid + 1;
			else rig = mid - 1;
		}
		return false;
    }
};

#define debug
#ifdef debug
int main(void) {
	Solution s;

	Mtx mtx = {
		 { 1,   3,  5,  7},
		 { 10, 11, 16, 20},
 		 { 23, 30, 34, 50}
	};

	cout << s.searchMatrix(mtx, 3) << endl;
	cout << s.searchMatrix(mtx, 13) << endl;
	return 0;
}
#endif


#define ll long long int
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

template <typename T>
void pv(T& v) {
	cout << "{";
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << "}" << endl;
}

template <typename T1, typename T2>
void pvv(T1& vv) {
	for(int i=0; i<vv.size(); i++)
		pv<T2>(vv[i]);
}

struct Node {
	int x, y, z;
	Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) { }
	bool operator < (const Node& o) const {
		if(x == o.x) {
			if(z == o.z) return y < o.y;
			return z < o.z;
		}
		return x<o.x;
	}
	bool operator == (Node& o) {
		bool bx = x==o.x || y==o.y || z==o.z;
		bool by = y==o.x || y==o.y || y==o.z;
		bool bz = z==o.x || z==o.y || z==o.z;
		return bx && by && bz;
	}
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > ret;
		int n = nums.size();
		if(n <= 0) return ret;
		sort(nums.begin(), nums.end());
		map<Node, int> mp;
		for(int i=0; i<n; i++) {
			int j = n-1, k = i+1;
			for( ; k<j; ) {
				int sum = nums[i]+nums[k]+nums[j];
				if(sum == 0) {
//					ret.push_back({nums[i], nums[j], nums[k]});
					Node node(nums[i], nums[j], nums[k]);
					int& rx = mp[Node(nums[i], nums[j], nums[k])];
					if(!rx) {
						ret.push_back({nums[i], nums[k], nums[j]});
						rx = true;
					}
					k++, j--;
				} else if(sum < 0) {
					k++;
				} else {
					j--;
				}
			}
		}

		return ret;
    }
};

#define debug
#ifdef debug
int main(void) {
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	Solution s;
	vector<vector<int> > ans = s.threeSum(nums);
	pvv<vector<vector<int> >, vector<int> >(ans);
	return 0;
}
#endif



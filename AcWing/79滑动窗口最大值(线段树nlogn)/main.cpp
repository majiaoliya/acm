#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug
class Solution {
public:
	int arr[MAXN], tree[MAXN<<2];
	void build(int rt, int lef, int rig) {
		if(lef == rig) {
			tree[rt] = arr[lef];
			return ;
		}
		int mid = (lef + rig) >> 1;
		build(rt<<1, lef, mid);
		build(rt<<1|1, mid+1, rig);
		tree[rt] = max(tree[rt<<1], tree[rt<<1|1]);
	}

	int query(int rt, int lef, int rig, int L, int R) {
		if(L<=lef && rig<=R) return tree[rt];
		int mid = (lef + rig) >> 1, lmax = 0, rmax = 0;
		if(L <= mid) lmax = query(rt<<1, lef, mid, L, R);
		if(mid < R) rmax = query(rt<<1|1, mid+1, rig, L, R);
		return max(lmax, rmax);
	}

    vector<int> maxInWindows(vector<int>& nums, int k) {
		vector<int> ret;
		/**
		for(int i=0; i<nums.size(); i++)
			arr[i+1] = nums[i];
		build(1, 1, nums.size());
		for(int i=k; i<=nums.size(); i++) {
			ret.push_back(query(1, 1, nums.size(), i-k+1, i));
		}
		*/
		priority_queue<int> q;
		for(int i=0; i<nums.size(); i++) {
			q.push(nums[i]);
			if(i < k) continue ;
			ret.push_back(q.top());
			q.pop();
		}
		ret.push_back(q.top());
		return ret;
	}
};

#ifdef debug
int main(void) {
	vector<int> v = { 2, 3, 4, 2, 6, 2, 5, 1 };
	Solution s;
	vector<int> rs = s.maxInWindows(v, 3);
	for(int i=0; i<rs.size(); i++)
		printf("%d ", rs[i]);
	return 0;
}
#endif

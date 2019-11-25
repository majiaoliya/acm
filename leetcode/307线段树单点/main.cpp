#include <stack>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#define debug
using namespace std;

#define MAXN (int)(1e6)

int tree[MAXN<<2];

class NumArray {
public:

	inline void push_up(int rt) { tree[rt] = tree[rt<<1] + tree[rt<<1|1]; }

	int n, va, L, R, idx;

    NumArray(vector<int>& nums) {
		n = nums.size();
		nums.insert(nums.begin(), 0);
        build(1, 1, n, nums);
    }
    
	void build(int rt, int lef, int rig, vector<int>& v) {
		if(lef == rig) {
			tree[rt] = v[lef];
			return ;
		}
		int mid = (lef + rig) >> 1;
		build(rt<<1, lef, mid, v);
		build(rt<<1|1, mid+1, rig, v);
		push_up(rt);
	}

	void upd(int rt, int lef, int rig) {
		if(lef == rig) {
			tree[rt] = va;
			return ;
		}
		int mid = (lef + rig) >> 1;
		if(idx <= mid) upd(rt<<1, lef, mid);
		else upd(rt<<1|1, mid+1, rig);
		push_up(rt);
	}

    void update(int i, int val) {
		this->va = val, this->idx = i;
		upd(1, 1, n);
	}
    
	int query(int rt, int lef, int rig) {
		if(L<=lef && rig<=R) return tree[rt];
		int mid = (lef+rig) >> 1, ret = 0;
		if(L<=mid) ret += query(rt<<1, lef, mid);
		if(mid<R) ret += query(rt<<1|1, mid+1, rig);
		return ret;
	}

    int sumRange(int i, int j) {
		this->L = i, this->R = j;
		return query(1, 1, n);
    }
};

#ifdef debug
int main(void) {
	vector<int> nums = {1, 3, 5};
	NumArray na(nums);
	printf("%d\n", na.sumRange(1, 3));
	na.update(2, 2);
	printf("%d\n", na.sumRange(1, 3));
	return 0;
}
#endif

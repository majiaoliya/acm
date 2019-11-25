#define ll long long int
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
#define debug

int cnt;

struct Node {
	int val, cnt, self;
	Node *lef, *rig;
	Node() : val(0), cnt(0), self(1), lef(0), rig(0) { }
	Node(int _val) : val(_val), cnt(0), self(1), lef(0), rig(0) { }
	~Node() { delete lef; delete rig; }
} ;

Node* insert(Node*& now, int val) {
	if(!now) { now = new Node(val); return now; }
	if(val == now->val) now->self += 1;
	else if(val > now->val) now->rig = insert(now->rig, val);
	else {
		now->lef = insert(now->lef, val);
		now->cnt ++;
	}
	return now;
}

int getsum(Node* now, int val) {
	if(!now) return 0;
	if(now->val == val) return now->cnt;
	if(now->val < val) 
		return now->cnt + now->self + getsum(now->rig, val);
	if(now->val > val)
		return getsum(now->lef, val);
	return 0;
}

class Solution {
public:
    //建立一颗二叉查找树
	//每个节点存一个cnt 记录比当前节点小的个数
    vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		if(!n) return {};
        Node* root = 0;
		vector<int> ans(n, 0), arr;
		for(int i=n-1; i>=0; i--) {
			cnt = 0;
			insert(root, nums[i]);
			ans[i] = getsum(root, nums[i]);
		}
        return ans;
    }
};

#ifdef debug
int main(void) {
	vector<int> nums = { 5, 2, 6, 1 };
	Solution s;
	vector<int> ans = s.countSmaller(nums);
	nums = {2, 0, 1};
	ans = s.countSmaller(nums);
	for(auto x : ans)
		cout << x << " ";
	cout << endl;
	return 0;
}
#endif




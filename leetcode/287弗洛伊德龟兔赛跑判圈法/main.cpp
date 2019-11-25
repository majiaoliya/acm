#define ll long long int
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#include <algorithm>

//给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
/**
 * 用弗洛伊德龟兔赛跑法:
 *  1:龟指针每次走一步, 兔指针每次走两步,如果兔指针为空就无环
 *  2:有环龟兔一定在环的起点相遇
 *  2:当龟兔相遇时
 */
class Solution {
public:
    int findDuplicate(vector<int>& v) {
		int fst = v[0]; //兔子(快指针每次走两步)
		int low = v[0]; //乌龟(慢指针每次走一步)
		//第一步:让龟兔相遇
		do {
			low = v[low];
			fst = v[v[fst]];
		} while(fst != low);
		//第二步:找到入口, 两个指针每次走一步
		int ptr1 = v[0]; //指针1从0开始
		int ptr2 = low; //指针2从乌龟开始
		while(ptr1 != ptr2) {
			ptr1 = v[ptr1];
			ptr2 = v[ptr2];
		}
		return ptr1;
    }
};
#define debug
#ifdef debug
int main(void) {
	vector<int> v = {1,3,4,2,2};
	vector<int> v2 = {3,1,3,4,2};
	Solution s;
	printf("%d\n", s.findDuplicate(v));
	printf("%d\n", s.findDuplicate(v2));
	return 0;
}
#endif

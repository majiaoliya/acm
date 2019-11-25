#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug

/**
 * 两个堆动态维护中位数
 * 小根堆存大的一半数字 
 * 大根堆反之
 * 
 * 插入一个数时:
 * 		1. 先插入大根堆
 * 		2. 如果大根堆堆顶大于小根堆堆顶, 就把大根堆的顶入小根堆, 小根堆的顶入大根堆
 * 		3. 如果大根堆size比小根堆size多2, 执行第二步
 * 		
 */

class Solution {
public:
	priority_queue<int> max_heap; //大根堆
	priority_queue<int, vector<int>, greater<int> > min_heap; //小根堆

	inline void swapit() {
		int minx = min_heap.top(), maxx = max_heap.top();
		min_heap.pop(), max_heap.pop();
		max_heap.push(minx), min_heap.push(maxx);
	}

	void insert(int num) {
        max_heap.push(num);
		if(max_heap.size() > min_heap.size()+1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		if(min_heap.size() && max_heap.top() > min_heap.top())
			swapit();
	}

    double getMedian() {
		if(max_heap.size() == min_heap.size())
			return (max_heap.top()+min_heap.top()) / 2.0;
		return max_heap.top();
    }
};

#ifdef debug
int main(void) {
	vector<int> v = { 1, 2, 3, 4 };
	Solution s;
	for(int i=0; i<v.size(); i++) {
		s.insert(v[i]);
		printf("%.2lf  ", s.getMedian());
	}
	return 0;
}
#endif

#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)2e6)
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#define ll long long int

using namespace std;

/**
 * 设计一个栈可以在常数时间内取最小值
 * 用多一个辅助栈维护 保持最小值始终在栈顶
 */
int m, arr[MAXN], rig, minx[MAXN], mrig;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { rig = mrig = 0; }
    
    void push(int x) {
		arr[++rig] = x;
		if(!mrig || minx[mrig]>=x) minx[++mrig] = x;
	}
    
    void pop() {
		if(!rig) return ;
		if(arr[rig] == minx[mrig]) mrig --;
		rig --;
    }
    
    int top() { return arr[rig]; }
    
    int getMin() { return minx[mrig]; }
};

#ifdef debug
int main() {
	vector<int> vec = { 2,7,4,1,8,1 };



	return 0;
}
#endif 



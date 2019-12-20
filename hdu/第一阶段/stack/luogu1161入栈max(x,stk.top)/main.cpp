#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <stack>
#include <queue>
#define MAXN ((int)2e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 栈的好题: 给定3个操作
 *    0: 一个数字入栈
 *    1: 出栈
 *    2: 查询栈内最大值
 * 解法一 : 可以用简单的线段树解
 * 解法二 : 入栈时入的是max(x, stk.top())
 */

int n, T, sz, tree[MAXN<<2];

void push_up(int rt) { tree[rt] = max(tree[rt<<1], tree[rt<<1|1]); }

void update(int rt, int lef, int rig, int id, int val) {
	if(lef == rig) { tree[rt] = val; return ; }
	int mid = (lef + rig) >> 1;
	if(id <= mid) update(rt<<1, lef, mid, id, val);
	else update(rt<<1|1, mid+1, rig, id, val);
	push_up(rt);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &T);
	stack<int> stk;
	/** 解法一
	while(T--) {
		int op;
		scanf("%d ", &op);
		if(op == 0) {
			int x;
			scanf("%d ", &x);
			++ sz;
			update(1, 1, MAXN-1, sz, x);
		} else if(op == 1) {
			update(1, 1, MAXN-1, sz, 0);
			sz --;
		} else 
			printf("%d\n", tree[1]);
	}
	*/

	//解法二 正解
	while(T--) {
		int op;
		scanf("%d ", &op);
		if(op == 0) {
			int x;
			scanf("%d ", &x);
			if(stk.empty()) stk.push(x);
			else stk.push(max(stk.top(), x)); //每次入栈入的是max(x,stk.top)
		} else if(op == 1) {
			if(!stk.empty()) stk.pop();
		} else
			printf("%d\n", stk.empty() ? 0 : stk.top());
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



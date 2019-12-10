#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)1e5+7)
#include <map>
#include <math.h>
#include <queue>
#define ll long long int
#define INF 0x3f3f3f3f
#define QAQ (0)

using namespace std;

/**
 * n个数,滑动窗口大小为K,每滑动一格打印窗口内的最大和最小值
 * 正解是O(n)的单调队列
 * 次优解是nlogn的优先级队列优化,本篇代码用的就是这个
 * 垃圾解是线段树
 */

int n, x, y, arr[MAXN], K;
struct Node { //存放每个数字的下标和值
	int id, val;
	Node(int _id=0, int _val=0) : id(_id), val(_val) { }
	bool operator > (const Node& y) const { return val > y.val; }
	bool operator < (const Node& y) const { return val < y.val; }
};


int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	priority_queue<Node> maxh;
	priority_queue<Node, vector<Node>, greater<Node> > minh;
	scanf("%d %d ", &n, &K);
	int i = 0;
	for(i=1; i<K; i++) { //先压入前k-1个数字
		scanf("%d ", &x);
		maxh.push(Node(i, x));
		minh.push(Node(i, x));
	}
	for( ; i<=n; i++) { //每次把值入队列前先把下标小于i-k的node弹出(不在[i-k,i]区间内的值)
		scanf("%d ", &x);
		while(minh.top().id <= i-K) minh.pop();
		while(maxh.top().id <= i-K) maxh.pop();
		maxh.push(Node(i, x));
		minh.push(Node(i, x));
		printf("%d %d\n", maxh.top().val, minh.top().val);	
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


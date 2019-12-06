#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)3e5+7)
#include <map>
#include <unordered_set>
#include <stdlib.h>
#define ll long long int
#define random(x) (rand()%x)

using namespace std;

/**
 * 给定n个数字,求他们组成的二叉排序树的后续遍历
 * 要先把数字全部随机打乱,才不会被卡成一条链,虽然题目没有卡
 */
int n;

struct Node {
	int val;
	Node* lef;
	Node* rig;
	Node(int _val=0) : val(_val), lef(0), rig(0) { }
} *root;

void insert(Node*& now, int val) {
	if(!now) {
		now = new Node(val);
		return ;
	}
	if(val <= now->val) insert(now->lef, val);
	else insert(now->rig, val);
}

int ans, arr[MAXN], sz;
void dfs(Node*& now, int level) {
	if(!now) return ;
	ans = max(level, ans);
	dfs(now->lef, level+1);
	dfs(now->rig, level+1);
	arr[sz++] = now->val;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	srand(time(0));
	for(int i=n, x; i>=1; i--) {
		scanf("%d ", arr+i);
	}
	for(int i=n-1; i>=1; i--) {
		int idx = random(i) + 1;
		printf("arr[idx]=%d, arr[i]=%d\n", arr[idx], arr[i]);
		swap(arr[idx], arr[i]);
	}
	forarr(arr, 1, n);
	for(int i=1; i<=n; i++)
		insert(root, arr[i]);
	dfs(root, 1);
	printf("deep=%d\n", ans);
	for(int i=0; i<sz; i++)
		printf("%d\n", arr[i]);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


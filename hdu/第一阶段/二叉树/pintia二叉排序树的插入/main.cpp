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
#include <queue>
#define MAXN ((int)64*1024)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给定一个二叉排序树的插入序列和多个询问序列q1, q2, q3...
 * 问询问序列q1,q2.q3的插入是否和给定的插入序列生成的二叉树一样
 * 因为是bst中序遍历有序,所以字需要比较先序遍历即可
 */

int n, m, x;

struct Node {
	int vis, val, lef, rig;
} tree[MAXN], tmp[MAXN];

void dfs(Node* arr, int now, vector<int>& vec) {
	if(!arr[now].vis) return ;
//	printf("%d, ", arr[now].val);
	vec.push_back(arr[now].val);
	dfs(arr, now<<1, vec);
	dfs(arr, now<<1|1, vec);
}

void insert(Node* arr, int now) {
	if(!arr[now].vis) {
		arr[now].val = x;
		arr[now].vis = true;
		return ;
	}
	if(x < arr[now].val) insert(arr, now<<1);
	else if(x > arr[now].val) insert(arr, now<<1|1);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m) && n) {
		memset(tree, false, sizeof(tree));
		for(int i=1; i<=n; i++) {
			scanf("%d ", &x);
			insert(tree, 1);
		}
		vector<int> src;
		dfs(tree, 1, src);
		while(m--) {
			memset(tmp, false, sizeof(tmp));
			for(int i=1; i<=n; i++) {
				scanf("%d ", &x);
				insert(tmp, 1);
			}
			vector<int> tv;
			dfs(tmp, 1, tv);
			bool ok = true;
			for(int i=0; i<(int)tv.size(); i++) 
				if(tv[i] != src[i]) { ok = false; break; }
			printf("%s\n", ok ? "Yes" : "No");
		}
	}


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



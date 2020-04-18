### luogu5076

> 您需要写一种数据结构，来维护一些数（ 都是 1e9以内的数字）的集合，最开始时集合是空的。其中需要提供以下操作，操作次数 $q$ 不超过 $10^4$：
>
> 1. 查询 $x$数的排名（排名定义为比当前数小的数的个数 $+1$。若有多个相同的数，因输出最小的排名）。
> 2. 查询排名为 $x$ 的数。
> 3. 求 $x$ 的前驱（前驱定义为小于 $x$，且最大的数）。
> 4. 求 $x$ 的后继（后继定义为大于 $x$，且最小的数）。
> 5. 插入一个数 $x$。

#### BST

* 查询排名为$K$的值
  1. 类似于权值线段树, 如果root的左子树节点个数$+1$大于$K$

  2. 则$K$大值一定在左子树    反之在右边子树

  3. ```c++
     int kth(Node* now, int K) { //第k小的值
     	if(!now) //题目要求一个意义不明的返回值
           return 2147483647; 
     	int tmp = now->lsum + 1;
     	if(tmp == K) 
     		return now->val;
     	if(tmp < K) //查右边记得减去lsum+1
     		return kth(now->rig, (K-tmp));
     	else 
     		return kth(now->lef, K);
     }
     ```

* 查询$x$的排名

  1. $x$的排名为: $x$的左子树个数$+1$,如果在root向右查询了要记得加上root的左子树的节点个数

  2. ```c++
     int xth(Node* now, int x, int K) { //查询x的排名
     	if(!now) return K;
     	if(now->val == x) 
           return K+now->lsum+1;
     	if(now->val < x) 
     		return xth(now->rig, x, K+(now->lsum+1));
     	else
     		return xth(now->lef, x, K);
     }
     ```

     ​

* 查询一个数$x$的前驱

  1. 如果$root$比$x$小,那么$root$可能是$x$的前驱, 且$root$的右子树也可能有$x$的前驱

  2. ```c++
     int get_pre(int key) {
     	int ret = -2147483647;
     	Node* p = root;
     	while(p) {
     		if(key > (p->val)) {
     			ret = p->val;
     			p = p->rig;
     		} else {
     			p = p->lef;
     		}
     	}
     	return ret;
     }
     ```

* 查询一个数$x$的后继

  1. 如果$root$比$x$大, 那么$root$可能是$x$的后继, 且$root$的左子树也可能有$x$的后继

  2. ```c++
     int get_suf(int key) {
     	int ret = 2147483647;
     	Node* p = root;
     	while(p) {
     		if(key < p->val) {
     			ret = p->val;
     			p = p->lef;
     		} else {
     			p = p->rig;
     		}
     	}
     	return ret;
     }
     ```

**完整代码**
```c++
#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif
//luoguP5076

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

struct Node {
	Node* lef;
	Node* rig;
	int val, lsum, rsum; //lsum,rsum定义左右子树的节点个数
	Node(int _val) : lef(0), rig(0), val(_val), lsum(0), rsum(0) { }
} *root;

void insert(Node*& now, int key) { //插入记得增加子树个数
	if(!now) {
		now = new Node(key);
		return ;
	}
	if(now->val <= key) 
		insert(now->rig, key), now->rsum ++;
	else 
		insert(now->lef, key), now->lsum ++;
}

bool find_key(Node* now, int key) {
	if(!now) return false;
	if(now->val == key) return true;
	if(now->val < key) 
		return find_key(now->rig, key);
	else
	   	return find_key(now->lef, key);
}

int kth(Node* now, int K) { //第k小的值
	if(!now) return 2147483647;
	int tmp = now->lsum + 1;
	if(tmp == K) 
		return now->val;
	if(tmp < K) 
		return kth(now->rig, (K-tmp));
	else 
		return kth(now->lef, K);
}

int xth(Node* now, int x, int K) { //查询x的排名
	if(!now) return K;
	if(now->val == x) return K+now->lsum+1;
	if(now->val < x) 
		return xth(now->rig, x, K+(now->lsum+1));
	else
		return xth(now->lef, x, K);
}

int get_pre(int key) {
	int ret = -2147483647;
	Node* p = root;
	while(p) {
		if(key > (p->val)) {
			ret = p->val;
			p = p->rig;
		} else {
			p = p->lef;
		}
	}
	return ret;
}

int get_suf(int key) {
	int ret = 2147483647;
	Node* p = root;
	while(p) {
		if(key < p->val) {
			ret = p->val;
			p = p->lef;
		} else {
			p = p->rig;
		}
	}
	return ret;
}

vector<int> vec;
void dfs(Node* now) {
	if(!now) return ;
	dfs(now->lef);
	vec.push_back(now->val);
	dfs(now->rig);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	freopen("out_main", "w", stdout);
	clock_t stime = clock();
#endif
	int n, x, op;
	scanf("%d ", &n);
	while(n--) {
		scanf("%d %d ", &op, &x);
		if(op == 5) insert(root, x);
      //这里的排名莫名其妙的要加1
		if(op == 1) printf("%d\n", xth(root, x, 0)+1);
		if(op == 2) printf("%d\n", kth(root, x));
		if(op == 3) printf("%d\n", get_pre(x));
		if(op == 4) printf("%d\n", get_suf(x));
	}
/**
	while(n--) {
		scanf("%d ", &x);
		insert(root, x);
	}
//	dfs(root);

	//for(auto it : vec)
	//	printf("%d %d\n", it, xth(root, it, 0));

//	for(int i=1; i<=9; i++)
//		printf("%d\n", kth(root, i));
//	for(auto it : vec)
//		printf("%d %d\n", it, get_suf(it));

*/





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


```


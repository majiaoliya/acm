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



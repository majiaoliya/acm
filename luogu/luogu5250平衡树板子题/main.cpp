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
#include <set>
#include <stack>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

#define FIND(x) (s.find(x) != s.end())

int n, m, a[MAXN], sz, op, len;
set<int> s;

int abs(int x) { return x > 0 ? x : -x; }

struct Node {
	Node* lef;
	Node* rig;
	int val, maxv;
	Node(int _val) : lef(0), rig(0), val(_val), maxv(_val) { }
	bool operator < (const Node& y) const {
		return val < y.val;
	}
	bool operator < (const Node* y) const {
		return val < y->val;
	}
} *root;

void insert(Node*& now, int key) {
	if(!now) {
		now = new Node(key);
		return ;
	}
	if(now->val > key) insert(now->lef, key);
	else insert(now->rig, key);
}

bool find_key(Node*& now, int key) {
	if(!now) return false;
	if(now->val == key) return true;
	if(now->val > key) return find_key(now->lef, key);
	else return find_key(now->rig, key);
}
/**
 * 查找前驱思路:
 * 如果key比根大, 则根可能是前驱,根的右子树也可能是前驱
 */
int get_pre(Node*& now, int key) {
	int ret = -1;
	stack<int> stk;
	Node* p = now;
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

/**
 * 查找后继
 * 如果key比根小 则根可能是后继, 根的左子树也可能是后继
 */
int get_suf(Node*& now, int key) {
	int ret = -1;
	Node* p = now;
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

Node* del(Node* root, int key) {
	if(!root) return 0;
	if(key < root->val) root->lef = del(root->lef, key);
	if(key > root->val) root->rig = del(root->rig, key);
	if(key == root->val) {
		if(!root->lef && !root->rig) { return 0; }
		if(root->lef) {
			Node* now = root->lef;
			while(now->rig) now = now->rig;
			swap(root->val, now->val);
			root->lef = del(root->lef, key);
		} else {
			Node* now = root->rig;
			while(now->lef) now = now->lef;
			swap(root->val, now->val);
			root->rig = del(root->rig, key);
		}
	}
	return root;	
}

void dfs(Node*& now) {
	if(now) {
		dfs(now->lef);
		printf("%d,", now->val);
		dfs(now->rig);
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	freopen("out_main", "w", stdout);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d ", &op, &len);
		if(op == 1) {
			if(find_key(root, len)) printf("Already Exist\n");
			else {
				insert(root, len);
				sz ++;
			}
		} else {
			if(!sz) printf("Empty\n");
			else {
				if(find_key(root, len)) {
					printf("%d\n", len);
					root = del(root, len);
					sz --;
				} else {
					int pre = get_pre(root, len);
					int suf = get_suf(root, len);
					if(-1 == pre) {
						printf("%d\n", suf);
						root = del(root, suf);
						sz --;
					} else if(-1 == suf) {
						printf("%d\n", pre);
						root = del(root, pre);
						sz --;
					} else {
						if((len-pre) <= (suf-len)) {
							printf("%d\n", pre);
							root = del(root, pre);
							sz --;
						} else {
							printf("%d\n", suf);
							root = del(root, suf);
							sz --;
						}
					}
				}
			}
		}
	}
	
	/**
	scanf("%d ", &n);
	while(n--) {
		int x;
		scanf("%d ", &x);
		insert(root, x);
	}
	dfs(root);
	printf("\n");
	printf("%d pre:%d suf:%d\n", 12, get_pre(root, 12), get_suf(root, 12));
	printf("%d pre:%d suf:%d\n", 94, get_pre(root, 94), get_suf(root, 94));
	printf("%d pre:%d suf:%d\n", 3, get_pre(root, 3), get_suf(root, 3));
	root = del(root, 3);
	dfs(root);
	printf("\n");

	root = del(root, 93);
	dfs(root);
	printf("\n");

	root = del(root, 498);
	dfs(root);
	printf("\n");
	*/


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



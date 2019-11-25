#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <unordered_set>
#define abs(x) (x > 0 ? x : -x)
#define ll long long int

using namespace std;

int n;
struct Node {
	int val;
	Node *lef, *rig;
	//	Node() : val(-1), lef(0), rig(0) { };
	Node(int v=-1) : val(v), lef(0), rig(0) { };
} *root;

int geth(Node* now) { return now ? max(geth(now->lef)+1, geth(now->rig)+1) : 0; }
int getbt(Node* now) {
	return now==0 ? : (geth(now->lef)-geth(now->rig));
}
Node* L(Node* a) { //顺时针旋转 LL型
	Node* b = a->lef;
	a->lef = b->rig;
	b->rig = a;
	return b;
}

Node* R(Node* a) { //逆时针旋转 RR型
	Node* b = a->rig;
	a->rig = b->lef;
	b->lef = a;
	return b;
}

Node* insert(Node* now, int val)  {
	if(!now) return new Node(val);
	if(val < now->val) {
		now->lef = insert(now->lef, val);
		if(getbt(now) == 2) {
			if(getbt(now->lef) == 1) now = L(now);
			else if(getbt(now->lef) == -1) {
				now->lef = R(now->lef);
				now = L(now);
			}
		}
	} else {
		now->rig = insert(now->rig, val);
		if(getbt(now) == -2) {
			if(getbt(now->rig) == -1) now = R(now);
			else if(getbt(now->rig) == 1) {
				now->rig = L(now->rig);
				now = R(now);
			}
		}
	}
	return now;
}

void dfs(Node* now) {
	if(now) {
		dfs(now->lef);
		printf("%d\n", now->val);
		dfs(now->rig);
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1, x; i<=n; i++) scanf("%d ", &x), root=insert(root, x);
	printf("%d\n", root ? root->val : 0);
//	printf("%d\n\n%d\n", root->val, getbt(root));
//	dfs(root);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




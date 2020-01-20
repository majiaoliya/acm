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
#include <set>
#include <time.h>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m;

struct Node {
	int val;
	Node* lef;
	Node* rig;
	Node(int _val=0) : val(_val), lef(0), rig(0) { }
} *ro;

void insert(Node*& root, int val) {
	if(!root) {
		root = new Node(val);
		return ;
	}
	if(val < root->val) insert(root->lef, val);
	else insert(root->rig, val);
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

void pit(Node* now) {
	if(!now) return ;
	pit(now->lef);
	printf("%d,", now->val);
	pit(now->rig);
}

void level_order() {
	int caset = 0;
	queue<Node*> q;
	q.push(ro);
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		if(now) printf("%s%d", caset++ ? " " : "", now->val);
		if(now && now->lef) q.push(now->lef);
		if(now && now->rig) q.push(now->rig);
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	int x;
	for(int i=1; i<=n; i++) {
		scanf("%d ", &x); 
		insert(ro, x);
//		printf("insert:%d \n", x);
	}
	scanf("%d ", &m);
	while(m--) {
		scanf("%d ", &x);
		ro = del(ro, x);
	}
//   	pit(ro);
	level_order();





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}





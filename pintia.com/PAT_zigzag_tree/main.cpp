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
#define ll long long int

using namespace std;

int n, q;
vector<int> PRE, IN;
struct Node {
	int val;
	Node *lef, *rig;
	Node(int v) : val(v), lef(0), rig(0) { }
} ;

void inorder(Node* now) {
	if(now) {
		inorder(now->lef);
		printf("%d, ", now->val);
		inorder(now->rig);
	}
}
void preorder(Node* now) {
	if(now) {
		printf("%d, ", now->val);
		preorder(now->lef);
		preorder(now->rig);
	}
}

map<int, Node*> mp;

Node* build(int ilef, int irig, int plef, int prig) {
	if(ilef > irig) return 0;
	if(ilef == irig) {
		Node* ret = new Node(IN[ilef]);
		mp[IN[ilef]] = ret;
		return ret;
	}
	Node* root = new Node(PRE[plef]);
	mp[PRE[plef]] = root;
	for(int i=ilef; i<=irig; i++) {
		if(IN[i] == PRE[plef]) {
			int cnt = i - ilef;
			root->lef = build(ilef, i-1, plef+1, plef+cnt);
			root->rig = build(i+1, irig, plef+cnt+1, prig);
			break; 
		}
	}
	return root;
}

Node* lca(Node* root, Node* p, Node* q) {
	if(!root) return 0;
	if(root==p || root==q) return root;
	auto lef = lca(root->lef, p, q);
	auto rig = lca(root->rig, p, q);
	if(lef && rig) return root;
	return lef ? lef : rig;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &q, &n);
	int x;
	for(int i=0; i<n; i++) 
		scanf("%d ", &x), PRE.push_back(x), IN.push_back(x);
	sort(IN.begin(), IN.end());
	Node* node = build(0, n-1, 0, n-1);
	//inorder(node);
	//printf("\n");
	//preorder(node);
	for(int i=0; i<q; i++) {
		int x,  y;
		scanf("%d %d ", &x, &y);
		Node* rp = mp[x];
		Node* rq = mp[y];
		if(!rp && !rq) {
			printf("ERROR: %d and %d are not found.\n", x, y);
		} else if(!rp || !rq) {
			printf("ERROR: %d is not found.\n", rp ? y : x);
			continue ;
		} else {
			Node* v = lca(node, rp, rq);
//			printf("%d %d %d\n", x, y, v?v->val:-1);
			if(v->val == x) 
				printf("%d is an ancestor of %d.\n", x, y);
			else if(v->val == y)
				printf("%d is an ancestor of %d.\n", y, x);
			else
				printf("LCA of %d and %d is %d.\n", x, y, v->val);

		}
	}




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


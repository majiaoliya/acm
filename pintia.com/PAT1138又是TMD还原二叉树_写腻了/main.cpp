#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 100005
using namespace std;

bool tag = false;

struct Node {
	int val;
	Node* lef, *rig;
	Node(int v) : val(v), lef(0), rig(0) { }
	Node() : val(0), lef(0), rig(0) { }
	void pre() {
		printf("%d,", val);
		if(lef) lef->pre();
		if(rig) rig->pre();
	}
	void in() {
		if(lef) lef->in();
		printf("%d,", val);
		if(rig) rig->in();
	}
	void pos() {
		if(lef) lef->pos();
		if(rig) rig->pos();
		if(tag) return;
		printf("%d", val);
		tag = true;
	}
};

int n;

int pre[MAXN], in[MAXN];

Node* re_build(int il, int ir, int pl, int pr) {
	if(il == ir) {
		Node* root = new Node(in[il]);
		return root;
	} else if(il < ir) {
		Node* root = new Node(pre[pl]);
		for(int i=il,cnt=0; i<=ir; i++) {
			if(in[i] == pre[pl]) {
				root->lef=re_build(il,i-1,pl+1,pl+cnt);
				root->rig=re_build(i+1,ir,pl+cnt+1,pr);
				break;
			}
			cnt ++;
		}
		return root;
	}
	return 0;
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=0; i<n; i++) 
		scanf("%d", pre+i);
	for(int i=0; i<n; i++) 
		scanf("%d", in+i);
	Node* root = re_build(0, n-1, 0, n-1);
//	if(root) root->pre();
//	printf("\n");
//	if(root) root->in();
	if(root)
		root->pos();
	return 0;
}


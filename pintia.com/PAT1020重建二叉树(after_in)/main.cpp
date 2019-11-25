#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 4096
using namespace std;

struct Node {
	int val;
	Node* lef, *rig;
	Node() : val(0), lef(0), rig(0) { }
	Node(int v) : val(v), lef(0), rig(0) { }
	void in() {
		if(lef) lef->in();
		printf("%d,", val);
		if(rig) rig->in();
	}
	void aft() {
		if(lef) lef->aft();
		if(rig) rig->aft();
		printf("%d,", val);
	}
	void level() {
		queue<Node*> q;
		q.push(this);
		int c = 0;
		while(!q.empty()) {
			Node* x = q.front();
			q.pop();
			if(x) {
				if(c++) printf(" ");
				printf("%d", x->val);
				q.push(x->lef);
				q.push(x->rig);
			}
		}
	}
};

vector<int> mid, aft;

Node* re_build(vector<int>& in, vector<int>& aft) {
	if(in.empty() || aft.empty()) return 0;
	vector<int> in_lef, in_rig, aft_lef, aft_rig;
	int root = aft[aft.size()-1];
	bool is_lef = true;
	for(int i=0; i<in.size(); i++) {
		if(root == in[i]) { is_lef = false; continue; }
		if(is_lef)
			in_lef.push_back(in[i]), aft_lef.push_back(aft[i]);
		else
			in_rig.push_back(in[i]), aft_rig.push_back(aft[i-1]);
	}
	Node* nroot = new Node(root);
	nroot->lef = re_build(in_lef, aft_lef);
	nroot->rig = re_build(in_rig, aft_rig);
	return nroot;
}

int main() {
	freopen("test", "r", stdin);
	
	int n, x;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		aft.push_back(x);
	}
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		mid.push_back(x);
	}
	
	Node* root = re_build(mid, aft);
//	if(root) root->in();
//	printf("\n");
//	if(root) root->aft();
	if(root) root->level();
	
	return 0;
}

























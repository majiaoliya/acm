#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <set>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n, c;
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
	
	void aft() {
		if(lef) lef->aft();
		if(rig) rig->aft();
		if(c++) printf(" ");
		printf("%d", val);
	}
	
};

vector<int> pre, in;
stack<int> stk;

Node* re_build(vector<int>& in, vector<int>& pre) {
	if(in.size() == 1) {
		Node* root = new Node(in[0]);
		return root;
	} else if(in.size()) {
		int rv = pre[0];
		Node* root = new Node(rv);
		vector<int> in_lef, in_rig, pre_lef, pre_rig;
		bool get_lef = true;
		for(int i=0, k=1; i<in.size(); i++) {
			if(in[i] == rv) { get_lef = false; continue ; }
			if(get_lef) {
				in_lef.push_back(in[i]);
				pre_lef.push_back(pre[k]);
			} else {
				in_rig.push_back(in[i]);
				pre_rig.push_back(pre[k]);
			}
			k++;
		}
		root->lef = re_build(in_lef, pre_lef);
		root->rig = re_build(in_rig, pre_rig);
		return root;
	}
	return 0;
}

int main()
{
	freopen("test", "r", stdin);
	cin >> n;
	string str;
	for( ; cin >> str; ) {
		if(str[1] == 'u') { //push
			int x;
			cin >> x;
			stk.push(x);
			pre.push_back(x);
		} else { //pop
			in.push_back(stk.top());
			stk.pop();
		}
	}
	
	Node* root = re_build(in, pre);
	if(root)
		root->aft();
	return 0;
}


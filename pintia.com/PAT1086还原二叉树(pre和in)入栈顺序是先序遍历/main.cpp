#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;
int n, c = 0;

struct Node {
	int val;
	Node* lef, *rig;
	Node(int _val) : val(_val), lef(0), rig(0) { }
	Node() : lef(0), rig(0) { }
	
	void level_order() {
		queue<Node*> q;
		q.push(this);
		while(!q.empty()) {
			Node* x = q.front();
			q.pop();
			if(x == 0) continue ;
			printf("%d,", x->val);
			q.push(x->lef), q.push(x->rig);
		}
	}
	void pos_order() {
		if(lef) lef->pos_order();
		if(rig) rig->pos_order();
		if(c++) printf(" ");
		printf("%d", val);
	}
};

vector<int> mid, pre;

Node* re_build(vector<int>& pre, vector<int>& mid) {
	if(pre.size()) {
		int root = pre[0];
		Node* nroot = new Node(root);
		if(pre.size() == 1) return nroot;
		
		vector<int> pre_lef, mid_lef, pre_rig, mid_rig;
		bool get_lef = true;
		for(int i=0, prei=1; i<mid.size(); i++) {
			if(mid[i] == root) { get_lef = false; continue; }
			else {
				if(get_lef) {
					pre_lef.push_back(pre[prei]);
					mid_lef.push_back(mid[i]);
				} else {
					pre_rig.push_back(pre[prei]);
					mid_rig.push_back(mid[i]);
				}
				prei ++;
			}
		}
		nroot->lef = re_build(pre_lef, mid_lef);
		nroot->rig = re_build(pre_rig, mid_rig);
//		for(int i=0; i<pre_lef.size(); i++)
//			printf("%d,", pre_lef[i]);
//		printf("\n");
//		for(int i=0; i<mid_lef.size(); i++)
//			printf("%d,", mid_lef[i]);
//		printf("\n");
//		for(int i=0; i<pre_rig.size(); i++)
//			printf("%d,", pre_rig[i]);
//		printf("\n");
//		for(int i=0; i<mid_rig.size(); i++)
//			printf("%d,", mid_rig[i]);
//		printf("\n");
		return nroot;
	}
	return 0;
}

int main()
{
    freopen("test", "r", stdin); 
    scanf("%d", &n);
    if(!n) return 0; //空树
    
    stack<int> stk;
    vector<int> v;
    char buf[16];
    for(int i=1; i<=2*n; i++) { 
    	scanf("%s", buf);
    	if(buf[2] == 's') { //push
    		int x;
    		scanf("%d", &x);
    		stk.push(x);
    		pre.push_back(x); // 入栈顺序是先序遍历
    	} else if(buf[2] == 'p') { //pop
    		mid.push_back(stk.top());
    		stk.pop();
    	}
    }
    
//    for(int i=1; i<=n; i++) //这里要注意:入栈顺序才是先序遍历
//    	pre.push_back(i);
    
    Node* root = re_build(pre, mid);
    root->pos_order();
    return 0;
}


#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <algorithm>
#include <stack>
#define MAXN 100086
using namespace std;

int n;
vector<int> in, aft;

struct Node {
	Node* lef, *rig;
	int val, level;
	Node() : lef(0), rig(0) { }
	Node(int v) : lef(0), rig(0), val(v) { }
	//思路:之字形打印
	// 依旧是层序遍历, 
	// 但是要在栈和队列里来回的切换
	// 当层数发生改变: 切换栈和队列 同时把栈或队列里的值全部打印
	// 例如:第一场切换到第二层时, 需要切换
	void level_order() {
		queue<Node*> q;
		q.push(this);
		bool tag = true; // false=queue, true=stack
		int c = 0, lst = 0;
		queue<int> v;
		stack<int> stk;
		while(!q.empty()) {
			Node* n = q.front();
			q.pop();
			
			if(n) { //第n个节点 level == 1是root
				if(n->level == 1) { lst = 1; printf("%d", n->val); }
				else { //非root
					if(lst != n->level) { //层数改变 切换栈和队列
						if(tag) {
							while(!stk.empty()) {
								printf(" %d", stk.top());
								stk.pop();
							}
						} else {
							while(!v.empty()) {
								printf(" %d", v.front());
								v.pop();
							}
						}
						tag = !tag; //修改
						lst = n->level; //修改为新的层数
					}
					if(tag) stk.push(n->val);
					else v.push(n->val);
				}
				
				if(n->lef) q.push(n->lef); //左右节点入队
				if(n->rig) q.push(n->rig);
			}
		}
		if(tag) {
			while(!stk.empty()) {
				printf(" %d", stk.top());
				stk.pop();
			}
		} else {
			while(!v.empty()) {
				printf(" %d", v.front());
				v.pop();
			}
		}
	}
};

void dfs(Node* n, int level) { //dfs设置level
	if(n) {
		n->level = level;
		dfs(n->lef, level+1);
		dfs(n->rig, level+1);
	}
}

Node* re_build(vector<int>& in, vector<int>& aft) {
	if(in.size() == 1) {	
		Node* n = new Node(in[0]);
		return n;
	} else if(in.size()) {
		int r = aft[aft.size()-1];
		Node* n = new Node(r);
		
		vector<int> lef_in, lef_aft, rig_in, rig_aft;
		bool get_lef = true;
		for(int i=0, k=0; i<in.size(); i++) {
			if(in[i] == r) { get_lef = false; continue; }
			if(get_lef) {
				lef_in.push_back(in[i]);
				lef_aft.push_back(aft[k]);
			} else {
				rig_in.push_back(in[i]);
				rig_aft.push_back(aft[k]);
			}
			k ++;
		}
		
		n->lef = re_build(lef_in, lef_aft);
		n->rig = re_build(rig_in, rig_aft);
		return n;
	}
	return 0;
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=0, x; i<n; i++) {
		scanf("%d", &x);
		in.push_back(x);
	}
	for(int i=0, x; i<n; i++) {
		scanf("%d", &x);
		aft.push_back(x);
	}
	Node* root = re_build(in, aft);
	if(root) {
		dfs(root, 1);
		root->level_order();
	}
    return 0;
}


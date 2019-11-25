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
#include <stack>
#define abs(x) (x > 0 ? x : -x)
#define ll long long int

using namespace std;

int n, pre[MAXN], ino[MAXN];
char str[32];

struct Node {
	int val;
	Node *lef, *rig;
	Node(int _v=0) : val(_v), lef(0), rig(0) { }
} ;

Node* build(int inl, int inr, int pl, int pr) {
	if(inl > inr) return 0;
	if(inl == inr) return new Node(ino[inl]);
	Node* node = new Node(pre[pl]);
	for(int i=inl; i<=inr; i++)
		if(ino[i] == node->val) {
			int cnt = i - inl;
			//node->lef = build(inl, i-1, pl+1, pl+cnt);
			//node->rig = build(i+1, inr, pl+1+cnt, pr);
			node->lef = build(inl, i-1, pl+1, pl+cnt);
			node->rig = build(i+1, inr, pl+cnt+1, pr);
			break;
		}
	return node;
}

int tag;
void dfs(Node* now) {
	if(now) {
		dfs(now->lef);
		dfs(now->rig);
		printf("%s%d", tag++?" " : "", now->val);
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d\n", &n);
	int i=1, j=1, x;
	stack<int> stk;
	while(~scanf("%s ", str)) {
		if(str[1] == 'u') { //push
			scanf("%d ", &x);
			stk.push(x);
			pre[i] = x;
			i++;
		} else {
			ino[j] = stk.top();
			stk.pop();
			j++;
		}
	}
	Node* root = build(1, n, 1, n);
#ifdef debug
	forarr(pre, 1, n, "pre");
	forarr(ino, 1, n, "ino");
#endif
	dfs(root);




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




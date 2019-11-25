/** L3_010 最后一个点过不了
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 32

using namespace std;

struct Node {
	Node* lef;
	Node* rig;
	int val;
	Node() : lef(0), rig(0), val(0) { }
	Node(int _val) : lef(0), rig(0), val(_val) { }
	
	void level_dsp() {
		queue<Node*> que;
		que.push(this);
		int c = 0;
		while(!que.empty()) {
			Node* x = que.front();
			que.pop();
			if(x == nullptr) continue ;
			if(c++) printf(" ");
			printf("%d", x->val);
			if(x->rig)
				que.push(x->rig); //顺序不要错了!!!先右再左
			if(x->lef)
				que.push(x->lef);
		}
	}
};

int n;
vector<int> vs[MAXN];

int cmp(int x, int y) { return x > y; }

void insert(Node*& pre, int val) { //插入节点
	if(pre == nullptr) {
		pre = new Node(val);
		return ;
	}
	int pval = pre->val;
	if(val > pre->val) {
		insert(pre->rig, val);
	} else if(val < pre->val) {
		insert(pre->lef, val);
	}
}

bool check_bfs(Node*& root) {
	bool ret = true, tag = false;
	queue<Node*> que;
	que.push(root);
	while(!que.empty()) {
		Node* x = que.front();
		que.pop();
		if(!tag) { //当没有找到第一个只有一个孩子节点
			if(!x->lef || !x->rig) { //这个x缺一个孩子
				tag = true;
			}
		} else { //找到第一个只有一个孩子节点了以后 队列里剩下的全部是叶节点 才是完全二叉树
			if(x == nullptr) continue;
			if(x->lef || x->rig) { //剩下的不是叶子 就false
				ret = false;
				break;
			}
		}
		que.push(x->rig); //顺序不要错了
		que.push(x->lef);
	}
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n); ) {
		int tval;
		scanf("%d", &tval);
		Node* root = new Node(tval);
		for(int i=2; i<=n; i++) {
			scanf("%d", &tval);
			insert(root, tval);
		}
		if(n) {
			bool ok = check_bfs(root);
			root->level_dsp();
			printf("\n%s\n", ok ? "YES" : "NO");
		} else if(n == 0) {
			printf("\nNO\n");
		}
	}
	return 0;
}
*/










/** AC 我还是写复杂了 主要是因为有知识盲区 (数组的顺序就是层序遍历顺序)*/
/**
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 32

using namespace std;
int n;
bool vis[MAXN<<2];
int tree[MAXN<<2]; //数组表示树

void insert(int root, int val) { //左子树=2*root  右子树=2*root+1
	int lef = root<<1, rig = root<<1|1;
	if(!vis[root]) {
		vis[root] = true;
		tree[root] = val;
		return ;
	}
	if(val > tree[root]) //插入左子树
		insert(lef, val);
	else if(val < tree[root]) //插入右子树
		insert(rig, val);
}

void level_order() { //层序遍历
	if(!n) return ;
	queue<int> q;
	q.push(1);
	int c = 0;
	while(!q.empty()) {
		int root = q.front(); q.pop();
		if(-1!=root && vis[root]) {
			if(c++) printf(" ");
			printf("%d", tree[root]);
			int lef = root<<1, rig = root<<1|1;
			q.push(lef), q.push(rig);
		}
	}
}

int main(void) {
//	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n); ) {
		memset(vis, false, sizeof(vis));
		memset(tree, -1, sizeof(tree));
		for(int i=1; i<=n; i++) {
			int tval;
			scanf("%d", &tval);
			insert(1, tval);
		}

		level_order(); //层序遍历
		bool ok = true;
		for(int i=1; i<=n; i++) //判断是否是完全二叉树([1,n]节点都铺满才是)
			if(vis[i] == false) { ok = false; break; }
		printf("\n%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
*/






/** 老师的代码 */
#include <bits/stdc++.h>
using namespace std;
#define maxN 1000

int main()
{
	freopen("test", "r", stdin);
	int tree[maxN], N, i, data, pos, flag, maxpos, count;

	scanf("%d", &N);
	for(i = 1; i <= maxN; i++)  //初始化
		tree[i] = -1;
	scanf("%d", &data);
	tree[1] = data;             //存入根
	maxpos = 1;
	for(i = 2; i <= N ;i++)
	{
		scanf("%d", &data);
		pos = 1;
		while(tree[pos] != -1)    // 对每一个插入的数据，找位置
		{
			if(data > tree[pos])
				pos = pos * 2;
			else
				pos = pos * 2 + 1;
		}
		tree[pos] = data;        // 存数据
		if(pos > maxpos)         // 保存最大的下标
			maxpos = pos;
	}
	flag = 0;
	for(i = 1; i <= maxpos; i++)  // 中途有空，就不是完全二叉树
		if(tree[i] == -1)
		{
			flag = 1;
		    break;
		}
	count = 0;
	for(i = 1; i < maxpos; i++)   // 层序输出，按数组顺序，只要不是-1，就输出
	{
		if(tree[i] != -1)
		{
			printf("%d ", tree[i]);
			count ++;
		}
		if(count == N - 1)
			break;
	}
	printf("%d\n", tree[maxpos]);
	if(flag == 1)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}








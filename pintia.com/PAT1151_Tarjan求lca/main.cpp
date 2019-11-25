//超内存, 段错误(可能有负数节点???)
//#include <iostream>
//#include <vector>
//#define MAXN 10005
//using namespace std;

//int n, m, bcj_pre[MAXN];

//bool marked[MAXN]; //标记点是否在树里
//bool vis[MAXN]; //tarjan vis[]

//struct Node {
//	Node* lef, *rig;
//	int val;
//	Node(int v) : val(v), lef(0), rig(0) { }
//	Node() : val(-1), lef(0), rig(0) { }
//	void pre_order() {
//		printf("%d ", val);
//		if(lef) lef->pre_order();
//		if(rig) rig->pre_order();
//	}
//};

//struct Query {
//	int x, y, lca;
//} query[MAXN];

//vector<int> in, pre;
//vector<int> Q[MAXN];

//Node* re_build(vector<int>& in, vector<int>& pre) {
//	if(in.size()) {
//		int rv = pre[0];
//		Node* root = new Node(rv);
//		vector<int> in_lef, in_rig, pre_lef, pre_rig;
//		bool get_lef = true;
//		for(int i=0, k=1; i<in.size(); i++) {
//			if(in[i] == rv) { get_lef = false; continue ; }
//			if(get_lef) {
//				in_lef.push_back(in[i]);
//				pre_lef.push_back(pre[k]);
//			} else {
//				in_rig.push_back(in[i]);
//				pre_rig.push_back(pre[k]);
//			}
//			k ++;
//		}
//		root->lef = re_build(in_lef, pre_lef);
//		root->rig = re_build(in_rig, pre_rig);
//		return root;
//	}
//	return 0;
//}

//void init() {
//	for(int i=1; i<=n; i++) 
//		bcj_pre[i] = -1;
//}

//int fa(int x) {
//	int ret = x;
//	while(bcj_pre[ret] != -1)
//		ret = bcj_pre[ret];
//	return ret;
//}

//void dfs(Node* u) { //Tarjan 求lca
//	if(!u) return ;
//	int val = u->val;
//	vis[val] = true;
//	for(int i=0; i<Q[val].size(); i++) {
//		int idx = Q[val][i];
//		if(query[idx].x == val) {
//			int v = query[idx].y;
//			if(vis[v])
//				query[idx].lca = fa(v);
//		} else if(query[idx].y == val) {
//			int v = query[idx].x;
//			if(vis[v])
//				query[idx].lca = fa(v);
//		}
//	}
//	Node* chl = nullptr;
//	for(int i=0; i<=1; i++) {
//		chl = i ? u->lef : u->rig;
//		if(chl) {
//			if(vis[chl->val]) continue ;
//			dfs(chl);
//			bcj_pre[chl->val] = val;
//		}
//	}
//}

//int main()
//{
//	freopen("test", "r", stdin);
//	scanf("%d %d", &m, &n);
//	init();
//	for(int i=1, x; i<=n; i++) {
//		scanf("%d", &x);
//		in.push_back(x);
//		marked[x] = true; //x出现过
//	}
//	for(int i=1, x; i<=n; i++) {
//		scanf("%d", &x);
//		pre.push_back(x);
//	}
//	Node* root = re_build(in, pre);
//	
//	for(int i=1; i<=m; i++) {
//		scanf("%d %d", &query[i].x, &query[i].y);
//		if(query[i].x>=0 && query[i].y>=0) {
//			Q[query[i].x].push_back(i);
//			Q[query[i].y].push_back(i);
//		}
//	}
//	
//	dfs(root);
//	for(int i=1; i<=m; i++) {
//		int x = query[i].x, y = query[i].y, lca = query[i].lca;
//		if(marked[x] && marked[y]) {
//			if(x!=lca && y!=lca)
//				printf("LCA of %d and %d is %d.\n", x, y, lca);
//			else if(x==lca && y!=lca)
//				printf("%d is an ancestor of %d.\n", lca, y);
//			else if(x!=lca && y==lca) 
//				printf("%d is an ancestor of %d.\n", lca, x);
//		} else if(marked[x] && !marked[y]) {
//			printf("ERROR: %d is not found.\n", y);
//		} else if(!marked[x] && marked[y]) {
//			printf("ERROR: %d is not found.\n", x);
//		} else if(!marked[x] && !marked[y]) {
//			printf("ERROR: %d and %d are not found.\n", x, y);
//		}
////		printf("query[%d,%d] = %d\n", query[i].x, query[i].y, query[i].lca);
//	}
//	return 0;
//}



#include <iostream>
#include <vector>
#include <set>
#define MAXN 100005
using namespace std;

struct Node {
	Node* lef, *rig;
	int val;
	bool vis;
	Node(int v) : val(v), lef(0), rig(0), vis(0) { }
	void pre() {
		printf("%d,", val);
		if(lef) lef->pre();
		if(rig) rig->pre();
	}
};

int n, t;

int in[MAXN], pre[MAXN];

Node* re_build(int il, int ir, int pl, int pr) {
	if(il == ir) {
		return new Node(in[ir]);
	} else if(il < ir) {
		Node* root = new Node(pre[pl]);
		for(int i=il, cnt=0; i<=ir; i++) {
			if(in[i] == pre[pl]) {
				root->lef = re_build(il, i-1, pl+1, pl+cnt);
				root->rig = re_build(i+1, ir, pl+cnt+1, pr);
				break;
			}
			cnt ++;
		}
		return root;
	}
	return 0;
}

struct Query {
	int x, y, lca;
	int tag; // tag==-1(x存在)  tag==2(x和y都存在)  tag==1(y存在)
} query[MAXN];

set<int> s; 

void dfs(Node* u) { // tarjan 求btree的lca
	if(!u && u->vis) return;
	for(int i=0; i<Q[u->val].size(); i++) {
		int idx = Q[u->val][i];
		if(query[idx].x == u->val) {
			int v = query[idx].y;
		} else if(query[idx].y == u->val) {
			int v = query[idx].x;
			if(vis[v])
				query[idx].lca = 
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	
	scanf("%d %d", &t, &n);
	for(int i=0; i<n; i++) 
		scanf("%d", in+i);
	for(int i=0; i<n; i++) {
		scanf("%d", pre+i);
		s.insert(pre[i]);
	}
	
	for(int i=1; i<=t; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		set<int>::iterator xit=s.find(x)l, yit=s.find(y);
		
		if(xit!=s.end() && yit!=s.end()) {
			Q[x].push_back(i);
			Q[y].push_back(i);
			query[i].tag = 2; //两个点都在树里
		} else if(xit==s.end() && yit!=s.end()) {
			query[i].tag = 1; //y在树里
		} else if(xit!=s.end() && yit==s.end()) {
			query[i].tag = -1; //x在树里
		}
		query[i].x = x, query[i].y = y;
	}
	
	Node* root = re_build(0, n-1, 0, n-1);
	dfs(root);
	return 0;
}


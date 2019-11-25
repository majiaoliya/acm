//#include <iostream>
//#include <vector>
//#include <string.h>
//#include <math.h>
//#include <set>
//#include <queue>
//#include <algorithm>
//#define MAXN 10005
//using namespace std;

//int n, sum;

//int arr[MAXN];

//struct Node {
//	int w;
//	Node* lef, *rig;
//	Node(int _w) : w(_w), lef(0), rig(0) { }
//	Node() : w(0), lef(0), rig(0) { }
//	bool operator < (const Node& other) const {
//		return this->w < other.w;
//	}
//};

//struct cmp {
//	bool operator()(Node* x, Node* y) {
//		return x->w > y->w;
//	}
//};

//priority_queue<Node*, vector<Node*>, cmp> q;
//int my_sum = 0;

//void dfs(Node* node, int level) {
//	if(node) {
//		if(node->lef==0 && node->rig==0) {
//			my_sum += level*(node->w);
//		} else {
//			dfs(node->lef, level+1);
//			dfs(node->rig, level+1);
//		}
//	}
//}

//int main()
//{
//	freopen("test", "r", stdin);
//	
//	scanf("%d", &n);
//	for(int i=1; i<=n; i++) {
//		Node* node = new Node();
//		scanf("%d", &node->w);
//		q.push(node);
//	}
//	
//	while(q.size() > 1) {
//		Node* fst = q.top();
//		q.pop();
//		Node* sec = q.top();
//		q.pop();
//		Node* node = new Node(fst->w + sec->w);
//		node->lef = fst, node->rig = sec;
//		q.push(node);
//	}
//	dfs(q.top(), 0);
//	printf("%d\n", my_sum);
//	return 0;
//}





#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#define MAXN 10005
using namespace std;

int n, sum;

int arr[MAXN];

struct Node {
	int w;
	Node* lef, *rig;
	Node(int _w) : w(_w), lef(0), rig(0) { }
	Node() : w(0), lef(0), rig(0) { }
	bool operator < (const Node& other) const {
		return this->w < other.w;
	}
};

struct cmp {
	bool operator()(Node* x, Node* y) {
		return x->w > y->w;
	}
};

priority_queue<Node*, vector<Node*>, cmp> q;
int my_sum = 0;

void dfs(Node* node, int level) {
	if(node) {
		if(node->lef==0 && node->rig==0) {
			my_sum += level*(node->w);
		} else {
			dfs(node->lef, level+1);
			dfs(node->rig, level+1);
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		Node* node = new Node();
		scanf("%d", &node->w);
		q.push(node);
	}
	
	while(q.size() > 1) {
		Node* fst = q.top();
		q.pop();
		Node* sec = q.top();
		q.pop();
		Node* node = new Node(fst->w + sec->w);
		node->lef = fst, node->rig = sec;
		q.push(node);
	}
	dfs(q.top(), 0);
	printf("%d\n", my_sum);
	return 0;
}


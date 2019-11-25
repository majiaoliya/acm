#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <regex>
#define MAXN 105

using namespace std;
int n;

struct Node {
	Node* lef;
	Node* rig;
	Node* par;
	int val, level;
	Node() : lef(0), rig(0), par(0), level(0) { }
	Node(int v, int l, Node*& p) : lef(0), rig(0), val(v), level(l) {
		par = p;
	}
};

map<int, Node*> table;

void insert(Node*& root, int val, int level, Node* par) {
	if(root == nullptr) {
		root = new Node(val, level, par);
		table[val] = root;
	} else {
		if(val < root->val) insert(root->lef, val, level+1, root);
		else insert(root->rig, val, level+1, root);
	}
}

void pre_order(Node*& root) {
	if(root) {
		pre_order(root->lef);
		printf("%d,", root->par ? 0 : root->par->val);
		pre_order(root->rig);
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	Node* root = nullptr;
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		insert(root, x, 1, 0);
	}

//	regex rgx1("(\\d.*?) is the root"),
//			rgx2("(\\d.*?) and (\\d.*?) are siblings"),
//			rgx3("\(\\d.*?) is the parent of (\\d.*?)"),
//			rgx4("(\\d.*?) is the left child of (\\d.*?)"),
//			rgx5("(\\d.*?) is the right child of (\\d.*?)"),
//			rgx6("(\\d.*?) and (\\d.*?) are on the same level");
	int t;
	scanf("%d", &t);
	cin.ignore();
	for(int i=0; i<t; i++) {
		string text;
		int a, b;
		string temp;
		cin >> a >> temp;
		if(temp == "is") {
			cin >> temp >> temp;
			if(temp == "root") {
				Node* x = table[a];
				if(x == nullptr) printf("No\n");
				else
					printf("%s\n", x->val==a ? "Yes":"No");
			} else if(temp == "left") {
				cin >> temp >> temp >> b;
				Node* B = table[b], *A = table[a];
				if(B && A && (B->lef)==A)
					printf("Yes\n");
				else
					printf("No\n"); 
			} else if(temp == "right") {
				cin >> temp >> temp >> b;
				Node* B = table[b], *A = table[a];
				if(B && A && (B->rig)==A)
					printf("Yes\n");
				else
					printf("No\n"); 
			} else if(temp == "parent") {
				cin >> temp >> b;
				Node* B = table[b], *A = table[a];
				if(B && A && (B->par)==A)
					printf("Yes\n");
				else
					printf("No\n"); 
			}
		} else if(temp == "and") {
			cin >> b >> temp >> temp;
			if(temp == "on") {
				cin >> temp >> temp >> temp;
				Node* B = table[b], *A = table[a];
				if(B && A && B->level==A->level)
					printf("Yes\n");
				else
					printf("No\n"); 
			} else if(temp == "siblings") {
				Node* B = table[b], *A = table[a];
				if(B && A && B->par==A->par)
					printf("Yes\n");
				else
					printf("No\n"); 
			}
		}
	}
	
	return 0;
}









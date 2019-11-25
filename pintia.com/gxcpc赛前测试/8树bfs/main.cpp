#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <map>
#include <queue>
#define MAXN 16
#include <algorithm>
using namespace std;

int n;
struct Node {
	int lef, rig;
	Node() : lef(-1), rig(-1) { }
} tree[MAXN];

bool has_root[MAXN];

int c=0;
void bfs(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if(tree[x].lef==-1 && tree[x].rig==-1) {
			if(c++) printf(" ");
			printf("%d", x);
		}
		if(tree[x].lef != -1)
			q.push(tree[x].lef);
		if(tree[x].rig != -1)
			q.push(tree[x].rig);
	}
}

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		char l, r;
		cin >> l >> r;
		if(l != '-') { tree[i].lef = l-'0', has_root[l-'0'] = true; }
		if(r != '-') { tree[i].rig = r-'0'; has_root[r-'0'] = true; }
	}
	int root = 0;
	for(int i=0; i<n; i++) {
		if(has_root[i] == 0) {
			root = i;
			break;
		}
	}
	
	bfs(root);
	
	return 0;
}


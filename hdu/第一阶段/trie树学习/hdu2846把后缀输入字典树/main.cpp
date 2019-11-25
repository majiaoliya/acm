/** what ? MLE ????
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#define MAX_SIZE 27
#define MAXN 10005
using namespace std;

int n, q, len;
char str[30];

struct Node {
	int sum, id;
	Node* next[MAX_SIZE];
	Node() : sum(0), id(0) { memset(next, false, sizeof(next)); }
	~Node() {
		for(int i=0; i<MAX_SIZE; i++)
			if(next[i]) delete next[i];
	}
} *root;

void insert(char* str, int lef, int rig, int num) {
	Node* p = root;
	for(int i=lef; i<=rig; i++) {
		int pos = str[i] - 'a';
		if( ! p->next[pos]) p->next[pos] = new Node;
		p = p->next[pos];
		if(num != p->id) p->sum ++;
		p->id = num;
	}
}

int find(char* str, int lef, int rig) {
	Node* p = root;
	for(int i=lef; i<=rig; i++) {
		int pos = str[i] - 'a';
//		printf("%c->", str[i]);
		if( ! p->next[pos]) return 0;
		p = p->next[pos];
	}
	return p->sum;
}

int tree[MAXN][MAX_SIZE], sum[MAXN], cnt;



int main(void) {
	freopen("test", "r", stdin);
	ios::sync_with_stdio(false);
	scanf("%d\n", &n);
	root = new Node;
	for(int i=1; i<=n; i++) {
		scanf("%s\n", str);
		len = strlen(str);
		for(int k=0; k<len; k++)
			insert(str, k, len-1, i);
	}
	scanf("%d", &q);
	while(q--) {
		scanf("%s", str);
		len = strlen(str);
//		printf("find(%s) = %d\n", str, find(str, 0, len-1));
		printf("%d\n", find(str, 0, len-1));
	}
	return 0;
}
*/



#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#define MAX_SIZE 27
#define MAXN (int)(1e6+5)
using namespace std;

int n, q, cnt, len, tree[MAXN][MAX_SIZE], sum[MAXN], id[MAXN];
char str[30];

void insert(char* s, int lef, int rig, int num) {
	int root = 0;
	for(int i=lef; i<=rig; i++) {
		int pos = s[i] - 'a';
		if( ! tree[root][pos]) tree[root][pos] = ++cnt;
		root = tree[root][pos];
		if(id[root] != num) sum[root] ++;
		id[root] = num;
	}
}

int find_(char* s, int lef, int rig) {
	int root = 0;
	for(int i=lef; i<=rig; i++) {
		int pos = s[i] - 'a';
		if( ! tree[root][pos]) return 0;
		root = tree[root][pos];
	}
	return sum[root];
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d\n", &n);
	for(int i=1; i<=n; i++) {
		scanf("%s", str);
		len = strlen(str);
		for(int k=0; k<len; k++)
			insert(str, k, len-1, i);
	}
	scanf("%d\n", &q);
	while(q--) {
		scanf("%s", str);
		len = strlen(str);
		printf("%d\n", find_(str, 0, len-1));
	}
	return 0;
}



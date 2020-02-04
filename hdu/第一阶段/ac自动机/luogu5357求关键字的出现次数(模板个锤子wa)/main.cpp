#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#define MAXN ((int)2e6+7)
#define ll long long int
#define QAQ (0)

using namespace std;

#define POS(x) (x - 'a')
#define TO(x) (x ? x : root)
int n, m, ans[MAXN];
char key[MAXN], text[MAXN];

struct Node {
	int id;
	Node* fail;
	Node* next[26];
	Node() : id(0), fail(0) { memset(next, false, sizeof(next)); }
} *root;

void insert(char* s, int id) {
	Node* now = root;
	for(int i=0; s[i]; i++) {
		if(!now->next[POS(s[i])]) now->next[POS(s[i])] = new Node();
		now = now->next[POS(s[i])];
	}
	now->id = id;
}

void build_fail() {
	queue<Node*> q;
	for(int i=0; i<26; i++)
		if(root->next[i]) {
			root->next[i]->fail = root;
			q.push(root->next[i]);
		}
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		for(int i=0; i<26; i++)
			if(now->next[i]) {
				now->next[i]->fail = TO(now->fail->next[i]);
				q.push(now->next[i]);
			} else {
				now->next[i] = now->fail->next[i];
			}
	}
}

//void build_fail() {
//	queue<Node*> q;
//	for(int i=0; i<26; i++) 
//		if(root->next[i]) {
//			q.push(root->next[i]);
//			root->next[i]->fail = root;
//		}
//	while(!q.empty()) {
//		auto now = q.front(); q.pop();
//		for(int i=0; i<26; i++) 
//			if(now->next[i]) {
//				now->next[i]->fail = TO(now->fail->next[i]);
//				q.push(now->next[i]);
//			} else 
//				now->next[i] = now->fail->next[i];
//	}
//}

void match(char* s) {
	Node* now = root;
	for(int i=0; s[i]; i++) {
		now = TO(now->next[POS(s[i])]);
		for(Node* t=now; t; t=t->fail)
			ans[t->id] ++;
	}
	for(int i=1; i<=n; i++)
		printf("%d\n", ans[i]);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	root = new Node();
	for(int i=1; i<=n; i++) {
		scanf("%s ", key);
		insert(key, i);
	}
	build_fail();
	scanf("%s ", text);
	match(text);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}







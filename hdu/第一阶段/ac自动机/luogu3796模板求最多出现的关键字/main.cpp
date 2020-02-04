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
#define MAXN ((int)1e6+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, tmp[256];
char keys[256][256], text[MAXN];

#define POS(x) (x - 'a')
#define TO(x) (x ? x : root)

/**
 * 给定多个关键字keys[], 和一个文本串text,
 * 要求打印出现次数最多的key[i]
 */

struct Node {
	int id;
	Node* fail;
	Node* next[26];
	Node() : id(0), fail(0) { memset(next, false, sizeof(next)); }
	~Node() {
		for(int i=0; i<26; i++)
			if(this->next[i]) delete this->next[i];
	}
} *root;

void insert(char* s, int id) {
	Node* now = root;
	for(int i=0; s[i]; i++) {
		if(!now->next[POS(s[i])]) now->next[POS(s[i])] = new Node();
		now = now->next[POS(s[i])];
	}
	now->id = id;
}

void build_fail() { //bfs构建fail指针
	queue<Node*> q;
	for(int i=0; i<26; i++)
		if(root->next[i]) {
			q.push(root->next[i]);
			root->next[i]->fail = root;
		}
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		for(int i=0; i<26; i++)
			if(now->next[i]) {
				//儿子的fail就是自己的fail对应第儿子
				//如果没有对应的儿子 就指向root
				now->next[i]->fail = TO(now->fail->next[i]);
				q.push(now->next[i]);
			} else {
				now->next[i] = now->fail->next[i];
			}
	}
}

void match(char* s) {
	Node* now = root;
	memset(tmp, false, sizeof(tmp));
	map<int, int> mp;
	int tmax = 0;
	for(int i=0; s[i]; i++) {
		now = TO(now->next[POS(s[i])]);
		for(Node* t=now; t; t=t->fail) {
			if(t->id)
				tmax = max(tmax, ++tmp[t->id]);
		}
	}
	printf("%d\n", tmax);
	for(int i=1; i<=n; i++)
		if(tmp[i]==tmax && tmp[i]) printf("%s\n", keys[i]);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d ", &n) && n) {
		root = new Node();
		for(int i=1; i<=n; i++) {
			scanf("%s ", keys[i]);
			insert(keys[i], i);
		}
		build_fail();
		scanf("%s ", text);
		match(text);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}





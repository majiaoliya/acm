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
#include <set>
#include <queue>
#define MAXN ((int)1e6+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, tmp[256], T;
char keys[64], text[MAXN];

#define POS(x) (x - 'a');
#define POSI (s[i]-'a')
#define TO(x) (x ? x : root)

struct Node {
	int cnt;
	Node* fail;
	Node* next[26];
	Node() : cnt(-1), fail(0) { memset(next, false, sizeof(next)); }
} *root;

void insert(char* s, int id) {
	Node* now = root;
	for(int i=0; s[i]; i++) {
		if(!now->next[POSI]) now->next[POSI] = new Node();
		now = now->next[POSI];
	}
	now->cnt = now->cnt==-1 ? 1 : now->cnt+1;
}

void build_fail() {
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
				now->next[i]->fail = TO(now->fail->next[i]);
				q.push(now->next[i]);
			} else
				now->next[i] = now->fail->next[i];
	}
}

int match(char* s) {
	int ans = 0;
	Node* now = root;
	for(int i=0; s[i]; i++) {
		now = TO(now->next[POSI]);
		for(Node* t=now; t && ~t->cnt; t=t->fail)
			ans += t->cnt, t->cnt = -1;
	}
	return ans;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &T);
	while(T--) {
		scanf("%d ", &n);
		root = new Node();
		for(int i=0; i<n; i++) {
			scanf("%s ", keys);
			insert(keys, i);
		}
		build_fail();
		scanf("%s ", text);
		printf("%d\n", match(text));
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}





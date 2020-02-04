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

#define GET(x) (x-'a')
//跳转到他的下个位置
#define TO(x) (x ? x : root)

int n, m;

char key[MAXN], text[MAXN];

struct node {
	int cnt;
	node* fail;
	node* next[26];
	node() : cnt(0), fail(0) { memset(next, false, sizeof(next)); }
} *root = new node();

void insert(char* s) {
	node* now = root;
	for(int i=0; s[i]; i++) {
		if(!now->next[GET(s[i])]) now->next[GET(s[i])] = new node();
		now = now->next[GET(s[i])];
	}
	now->cnt ++;
}

void build_fail() {
	queue<node*> q;
	for(int i=0; i<26; i++)
		if(root->next[i]) //根节点儿子的fail指向根
			q.push(root->next[i]), root->next[i]->fail = root;
	while(!q.empty()) {
		node* now = q.front(); q.pop();
		for(int i=0; i<26; i++) 
			if(now->next[i]) {
				/**
				 * 儿子的fail就是自己的fail对应的儿子
				 * 如果自己的fail没有对应的儿子,就指向root
				 * 最后吧儿子进队
				 */
				now->next[i]->fail = TO(now->fail->next[i]);
				q.push(now->next[i]);
			} else {
				//相当于并查集的路径压缩
				now->next[i] = now->fail->next[i];
			}
	}
}

int match(char* s) {
	node* now = root;
	int ans = 0;
	for(int i=0; s[i]; i++) {
		now = TO(now->next[GET(s[i])]);
		//(~t->cnt)等价于(t->cnt != -1)
		for(node* t=now; t && ~t->cnt; t=t->fail)
			ans += t->cnt, t->cnt = -1;
	}
	return ans;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) {
		scanf("%s ", key);
		insert(key);
	}
	build_fail();
	scanf("%s ", text);
	printf("%d\n", match(text));






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


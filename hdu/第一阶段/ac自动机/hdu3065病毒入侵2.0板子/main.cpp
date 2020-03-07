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
#define ll long long int
#define QAQ (0)
#define ch (s[i] - 'A')
//#define ch ((int) s[i])

using namespace std;

/** 
 * 给定多个关键字key[], 和一个询问文本text
 * 那些关键字key[i]出现的次数
 */

const int MAXN = 2000000 + 10;
int n, m;
#define Z (32)

//struct AC {
//	short sid[M];
//	int nxt[M][Z], fail[M], cnt[M], rig;
//	char key[1024][52], text[M];
//	void insert(char* s, int id) {
//		int now = root;
//		for(int i=0; s[i]; i++) {
//			if(!nxt[now][ch]) nxt[now][ch] = ++rig;
//			now = nxt[now][ch];
//		}
//		sid[now] = id;
//	}
//	void build() {
//		queue<int> q;
//		for(int i=0; i<Z; i++)
//			if(nxt[root][i]) q.push(nxt[root][i]);
//		while(!q.empty()) {
//			auto now = q.front(); q.pop();
//			for(int i=0; i<Z; i++)
//				if(!nxt[now][i]) 
//					nxt[now][i] = nxt[fail[now]][i];
//				else {
//					fail[nxt[now][i]] = nxt[fail[now]][i];
//					q.push(nxt[now][i]);
//				}
//		}
//	}
//	void match(char* s) {
//		int now = root;
//		for(int i=0; s[i]; i++) {
//			now = nxt[now][ch];
//			for(int t=now; t; t=fail[t])
//				if(sid[t]) cnt[sid[t]] ++;
//		}
//		for(int i=1; i<=n; i++)
//			if(cnt[i]) 
//				printf("%s: %d\n", key[i], cnt[i]);
//	}
//} ac;

struct Node {
	short sid;
	Node* fail;
	Node* next[Z];
	Node() : sid(0), fail(0) { memset(next, false, sizeof(Z)); }
} *root;

#define N (1024)
int cnt[N];
char key[N][64], text[MAXN];
void insert(char* s, int id) {
	Node* now = root;
	for(int i=0; s[i]; i++) {
		if(!now->next[ch]) now->next[ch] = new Node();
		now = now->next[ch];
	}
	now->sid = id;
}

#define TO(x) (x ? x : root)

void build() {
	queue<Node*> q;
	for(int i=0; i<Z; i++)
		if(root->next[i]) {
			q.push(root->next[i]);
			root->next[i]->fail = root;
		}
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		for(int i=0; i<Z; i++)
			if(now->next[i]) {
				now->next[i]->fail = TO(now->fail->next[i]);
				q.push(now->next[i]);
			} else
				now->next[i] = now->fail->next[i];
	}
}
void match(char* s) {
	Node* now = root;
	for(int i=0; s[i]; i++) {
		if(s[i]>='A' && s[i]<='Z') {
			now = TO(now->next[ch]);
			for(Node* t=now; t; t=t->fail)
				if(t->sid) cnt[t->sid] ++;
		} else
			now = root;
	}
	for(int i=1; i<=n; i++)
		if(cnt[i]) printf("%s: %d\n", key[i], cnt[i]);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	freopen("out1", "w", stdout);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	root = new Node();
	for(int i=1; i<=n; i++) {
		scanf("%s ", key[i]);
	   	insert(key[i], i);
	}
	build();
	cin.getline(text, sizeof(text));
	//for(int i=0; text[i]; i++)
	//	if(text[i]<32 && text[i]>126) return true;
	match(text);





#ifdef debug
	clock_t etime = clock();
#endif 
	return 0;
}





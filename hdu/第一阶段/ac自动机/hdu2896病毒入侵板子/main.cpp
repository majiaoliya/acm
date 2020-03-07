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
#define root (0)
#define ch ((int)s[i])

using namespace std;

/** 
 * 给定多个关键字key[], 和多个询问文本text
 * 对于每个询问打印出现了那些关键字key[i]
 * ac自动机板子题   内存卡的很死
 */

const int MAXN = 500*200 + 10;
int n, m, rig, ans;
int nxt[MAXN][128], fail[MAXN], sid[MAXN], vis[MAXN];
char buf[MAXN];

#define cls(x) (memset(x, false, sizeof(x)))
inline void init() { 
//	cls(nxt), cls(sid), cls(fail), cls(vis), cls(tmp);
	ans = rig = 0;
}

int newnode() {
	++ rig;
	for(int i=0; i<128; i++) nxt[rig][i] = 0;
	fail[rig] = 0;
	return rig;
}

void insert(char* s, int id) {
	int now = root;
	for(int i=0; s[i]; i++) {
		if(!nxt[now][ch]) nxt[now][ch] = newnode();
		now = nxt[now][ch];
	}
	sid[now] = id;
}

void search(char* s) {
	int now = root;
	for(int i=0; s[i]; i++) {
		if(!nxt[now][ch]) { printf("no have %s\n", s); return ; }
		now = nxt[now][ch];
	}
	printf("%s id : %d\n", s, sid[now]);
}

void build() {
	queue<int> q;
	for(int i=0; i<128; i++)
		if(nxt[root][i]) q.push(nxt[root][i]), fail[nxt[root][i]] = root;
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		for(int i=0; i<128; i++)
			if(nxt[now][i]) {
				fail[nxt[now][i]] = nxt[fail[now]][i];
				q.push(nxt[now][i]);
			} else
				nxt[now][i] = nxt[fail[now]][i];
	}
}

void query(char* s, int id) {
	int now = root, sz = 0;
	for(int i=0; s[i]; i++) {
		now = nxt[now][ch];
		for(int t=now; t; t=fail[t])
			if(sid[t]) {
				vis[sid[t]] = true;
				++ sz;
//				tmp[++sz] = sid[t];
			}
	}
	if(sz) {
		printf("web %d:", id);
		for(int i=1; i<=n; i++) 
			if(vis[i]) printf(" %d", i), vis[i] = 0;
		printf("\n");
		ans ++;
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d ", &n)) {
//		init();
		for(int i=1; i<=n; i++)
			scanf("%s ", buf), insert(buf, i);
		build();
		scanf("%d ", &m);
		for(int i=1; i<=m; i++) {
			scanf("%s ", buf);
			query(buf, i);
		}
		printf("total: %d\n", ans);
	}





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}





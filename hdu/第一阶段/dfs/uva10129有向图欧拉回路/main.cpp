//UVA10129
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
#include <stack>
#include <queue>
#define MAXN (128)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, Q, ind[128], vis[MAXN], outd[MAXN];
char buf[MAXN];

set<int> G[MAXN];
int cnt = 0;
void dfs(int now) {
	vis[now] = false;
	cnt ++;
	for(auto i : G[now]) 
		if(vis[i]) dfs(i);
}

void init() {
	memset(vis, 0, sizeof(vis));
	memset(ind, 0, sizeof(ind));
	memset(outd, 0, sizeof(outd));
	for(int i='a'; i<='z'; i++) G[i].clear();
	cnt = 0;
}

int check() {
	int _in = 0, _out = 0;
	for(int i='a'; i<='z'; i++) {
		if(vis[i]) return false;
		if(ind[i] != outd[i]) {
			if(ind[i]-outd[i] == 1) _in ++;
			else if(outd[i]-ind[i] == 1) _out ++;
			else return false;
		}
	}
	if((_in==1&&_out==1) || (_in==0&&_out==0)) return true;
	return false;
}

void pit() {
	for(int i='a'; i<='z'; i++) {
		printf("%c : ", i);
		for(auto v : G[i]) printf("->%c", v);
		printf("\n");
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &Q);
	while(Q--) {
		scanf("%d ", &n);
		init();
		int u, v;
		for(int i=1; i<=n; i++) {
			string str;
			getline(cin, str);
			u = str[0], v = str.back();
			G[u].insert(v), G[v].insert(u);
			ind[v] ++, outd[u] ++;
			vis[u] = vis[v] = true;
		}
		dfs(v);
		int ok = check();
		printf("%s\n", ok ? "Ordering is possible." :
			   	"The door cannot be opened.");
	}

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



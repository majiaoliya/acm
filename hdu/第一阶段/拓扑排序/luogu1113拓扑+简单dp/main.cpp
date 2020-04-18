//luogu1113
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
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, id, w[MAXN], ind[MAXN], tmax[MAXN], outd[MAXN];
int f[MAXN];
vector<int> G[MAXN];

int topsort() {
	queue<int> q;
	int ans = 0;
	for(int i=1; i<=n; i++)
		if(ind[i] == 0) q.push(i), f[i] = w[i];
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		if(outd[now] == 0) ans = max(ans, f[now]);
		for(auto chl : G[now]) {
			ind[chl] --;
			f[chl] = max(f[chl], f[now]+w[chl]);
			if(ind[chl] == 0) q.push(chl);
		}
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
		int v, tim;
		scanf("%d %d ", &id, &tim);
		w[id] = tim;
		while((scanf("%d ", &v)) && v) 
			G[v].push_back(id), ind[id] ++, outd[v] ++;
	}
	int ans = topsort();
	printf("%d\n", ans);








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



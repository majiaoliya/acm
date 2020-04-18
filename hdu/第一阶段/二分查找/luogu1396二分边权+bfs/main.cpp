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

int n, m, s, t;
bool vis[MAXN];
typedef pair<int,int> pii;
vector<pii> G[MAXN];

bool check(int maxd) {
	memset(vis, false, sizeof(vis));
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		auto u = q.front(); q.pop();
		if(u == t) return true;
		for(auto ed : G[u]) {
			if(ed.second <= maxd && !vis[ed.first]) {
//				printf("%d < %d\n", ed.second, maxd);
				q.push(ed.first);
				vis[ed.first] = true;
				if(u == t) return true;
			}
		}
	}
	return false;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d %d ", &n, &m, &s, &t);
	for(int i=1; i<=m; i++) {
		int u, v, w;
		scanf("%d %d %d ", &u, &v, &w);
		G[u].push_back({v, w}), G[v].push_back({u, w});
	}
	int lef = 1, rig = 1e4+7, mid, ans = 0;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		bool ok = check(mid);
//		printf("%d ok:%d\n", mid, ok);
		if(ok) {
			ans = mid;
			rig = mid - 1;
		} else {
			lef = mid + 1;
		}
	}
	printf("%d\n", ans);




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



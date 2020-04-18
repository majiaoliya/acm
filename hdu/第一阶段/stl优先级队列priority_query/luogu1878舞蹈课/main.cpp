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
#include <list>
#include <stack>
#include <queue>
#define MAXN ((int)2e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, boy[MAXN], a[MAXN], vis[MAXN], cnt;
char buf[MAXN];

int abs(int val) { return val > 0 ? val : -val; }
pair<int,int> ans[MAXN];

struct Node {
	int x, y, z;
	friend bool operator < (const Node& n1, const Node& n2) {
		if(n1.z == n2.z) return n1.x > n2.x;
		return n1.z > n2.z;
	}
} ;

priority_queue<Node, vector<Node> > q;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %s ", &n, buf+1);
	for(int i=1; i<=n; i++) 
		boy[i] = (buf[i] == 'B');
	for(int i=1; i<=n; i++) {
		scanf("%d ", a+i);
		if(i == 1) continue ;
		if(boy[i] ^ boy[i-1]) {
			q.push({i-1, i, abs(a[i]-a[i-1])});
		}
	}
	while(!q.empty()) {
		int x = q.top().x, y = q.top().y;
		q.pop();
		if(vis[x] || vis[y]) continue ;
		vis[x] = vis[y] = 1;
		cnt ++;
		ans[cnt].first = x, ans[cnt].second = y;
		while(x>0 && vis[x]) --x; //x最多是O(n)
		while(y<=n && vis[y]) ++y; //y最多是O(n)
		if(x>0 && y<=n && boy[x] ^ boy[y]) q.push({x, y, abs(a[x]-a[y])});
	}
	printf("%d\n", cnt);
	for(int i=1; i<=cnt; i++) printf("%d %d\n", ans[i].first, ans[i].second);



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <queue>
#define ll long long int

using namespace std;

int n;
/**
 * 给定n个数字, 求这n个数字生成的哈夫曼树的带权路径长度WPL
 */
struct Node {
	int lef, rig, w, id;
	Node(int _w=0, int _id=0) : lef(0), rig(0), w(_w), id(_id) { }
	bool operator < (const Node& y) const { return w > y.w; }
} arr[MAXN];

priority_queue<Node> q;

int sum;
void dfs(int now, int level) {
	if(now == 0) return ;
	if(arr[now].lef==0 && arr[now].rig==0) {
//		printf("level:%d w:%d\n", level, arr[now].w);
		sum += level*arr[now].w;
		return ;
	}
	dfs(arr[now].lef, level+1);
	dfs(arr[now].rig, level+1);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		scanf("%d ", &arr[++cnt].w);
		arr[cnt].id = i;
		q.push(arr[cnt]);
	}
	while(q.size() > 1) {
		auto x = q.top(); q.pop();
		auto y = q.top(); q.pop();
		++cnt;
		arr[cnt].w = x.w + y.w;
		arr[cnt].lef = x.id, arr[cnt].rig = y.id;
		arr[cnt].id = cnt;
		q.push(arr[cnt]);
	}
	dfs(q.top().id, 0);
	printf("%d\n", sum);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
const int maxn = 220;
const int inf = 1<<30;

int n, m, s, t;
struct Node {
	int v, val, next;
} node[201010];

int top = 1, head[101010];

inline void addedge(int u, int v, int val) {
	node[++top].v = v;
	node[top].val = val;
	node[top].next = head[u];
	head[u] = top;
}

inline int Read() {
	int x = 0; 
	char c = getchar();
	while(c>'9' || c<'0') c = getchar();
	while(c>='0' && c<='9') x = x*10 + c-'0', c = getchar();
	return x;
}

int inque[101010];
struct Pre {
	int v, edge;
} pre[101010];

bool bfs() {
	queue<int> q;
	memset(inque, false, sizeof(inque));
	memset(pre, -1, sizeof(pre));
	inque[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=head[u]; i; i=node[i].next) {
			int d = node[i].v;
			if(!inque[d] && node[i].val) { //node[i].val==0则已经该路径满了
				pre[d].v = u;
				pre[d].edge = i;
				if(d == t) return 1;
				inque[d] = 1;
				q.push(d);
			}
		}
	}
	return 0;
}

int EK() {
	int ans = 0;
	while(bfs()) {
		int mi = inf;
		for(int i=t; i!=s; i=pre[i].v)
			mi = min(mi, node[pre[i].edge].val);
		for(int i=t; i!=s; i=pre[i].v) {
			node[pre[i].edge].val -= mi;
			node[pre[i].edge^1].val += mi; //反向边的编号是正向边的编号^1
										   //所以top开始时必须是奇数
		}
		ans += mi;
	}
	return ans;
}

int main(void) {
	freopen("test", "r", stdin);
	register int i;
	n = Read(), m = Read(), s = Read(), t = Read();
	int u, v, w;
	for(i=1; i<=m; i++)
		u=Read(), v=Read(), w=Read(), addedge(u, v, w), addedge(v, u, 0);
	printf("%d\n", EK());
	return 0;
}

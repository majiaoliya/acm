#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 505
#define INF (1<<30)
#include <map>
#include <queue>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, m, row, col, A, B;
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

typedef pair<int,int> pii;
int tim[MAXN][MAXN];
bool tag[MAXN][MAXN]; // 标记这个位置是否有领主
bool vis[MAXN][MAXN];

struct Node {
	int r, c, step;
	Node() : r(0), c(0), step(0) { }
	Node(int _r, int _c, int _s) : r(_r), c(_c), step(_s) { }
};
queue<Node> que;
Node arr[100005]; //B数组

void init() {
	for(int i=0; i<MAXN; i++)
		for(int k=0; k<MAXN; k++)
			tim[i][k] = INF;
}

void bfs() {
	while(!que.empty()) {
		Node now = que.front();
		que.pop();
		vis[now.r][now.c] = true;
		if(tag[now.r][now.c]) tim[now.r][now.c] = min(now.step, tim[now.r][now.c]);
		for(int i=0; i<4; i++) {
			int nr = now.r+dr[i], nc = now.c+dc[i];
			if(nr<1 || nc<1 || nr>row || nc>col) continue ;
			if(vis[nr][nc] || tim[nr][nc]<now.step) continue ;
			vis[nr][nc] = true;
			que.push(Node(nr, nc, now.step+1));
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	init();
	scanf("%d %d %d %d ", &row, &col, &A, &B);
	int r, c;
	for(int i=1; i<=A; i++) {
		scanf("%d %d ", &r, &c);
		tim[r][c] = 0;
		que.push(Node(r, c, 0)); //所有感染源入队列
	}
	for(int i=1; i<=B; i++) {
		scanf("%d %d ", &r, &c);
		arr[i].r = r, arr[i].c = c;
		tag[r][c] = true;
	}
	bfs();
	for(int i=1; i<=B; i++)
		printf("%d\n", tim[arr[i].r][arr[i].c]);




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


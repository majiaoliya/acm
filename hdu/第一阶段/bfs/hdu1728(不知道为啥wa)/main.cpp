//#include <iostream>
//#include <algorithm>
//#include <math.h>
//#include <string.h>
//#include <queue>
//#include <vector>
//#define MAXN 105
//using namespace std;
//
//int t, n, m, k, xs, ys, xe, ye;
//char mtx[MAXN][MAXN];
//bool vis[MAXN][MAXN];
//
//int dx[] = { 1, -1, 0, 0 };
//int dy[] = { 0, 0, 1, -1 };
//int d[] = { 1, 2, 3, 4 };
//
//struct Node {
//	int x, y, step, dir, turn;
//} ;
//
//inline void init() {
//	memset(vis, false, sizeof(vis));
//}
//
//bool check(int x, int y) {
//	return (x>=0 && x<m && y>=0 && y<n && !vis[x][y] && mtx[x][y]=='.');
//}
//
//int bfs() {
//	int ret = -1;
//	queue<Node> q;
//	Node x, nx;
//	x.x = xs, x.y = ys, x.step = 0, x.turn = 0, x.dir = 0;
//	q.push(x);
//
//	while(!q.empty()) {
//		x = q.front(); q.pop();
//		if(x.x==xe && x.y==ye) { ret = x.step; printf("find(%d)\n", x.dir); break; }
//		vis[x.x][x.y] = true;
//		
//		for(int i=0; i<4; i++) {
//			nx.x = x.x+dx[i], nx.y = x.y+dy[i], nx.step = x.step+1;
//			if(x.step == 0) x.dir = d[i];
//			nx.turn = x.dir==d[i] ? x.turn : x.turn+1;
//			nx.dir = d[i];
//			if(check(nx.x, nx.y) && nx.turn<=k) {
//				q.push(nx);
//			}
//		}
//	}
//	return ret;
//}
//
//int main(void) {
//	freopen("test", "r", stdin);
//	scanf("%d\n", &t);
//	while(t--) {
//		init();
//		scanf("%d %d\n", &m, &n);
//		for(int i=0; i<m; i++)
//			scanf("%s\n", mtx[i]);
//		scanf("%d %d %d %d %d\n", &k, &xs, &ys, &xe, &ye);
//		xs--, ys--, xe--, ye--;
//		printf("%d\n", bfs());
//	}
//	return 0;
//}
//
//


#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char s[105][105];
int n,m;
int k,x1,y1,x2,y2;
int flag;
int v[105][105];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct node{
    int x,y;
    int cnt;
};

int bfs()

{
    queue<node> q;
    memset(v,0,sizeof(v));
    node f,t;
    f.x = x1;
    f.y = y1;
    f.cnt = -1;
    q.push(f);
    while(!q.empty())
    {
        node h = q.front();
        q.pop();
        if(h.x == x2 && h.y == y2 && h.cnt <= k)
            return 1;
        t.cnt = h.cnt + 1;
        for(int i = 0;i < 4;++i)
        {
            t.x = h.x + dx[i];
            t.y = h.y + dy[i];
            while(!(t.x < 1 || t.x > n || t.y < 1 || t.y > m) && s[t.x][t.y] == '.')
            {
                if(!v[t.x][t.y])
                {
                    q.push(t);
                    v[t.x][t.y] = 1;
                }
                t.x += dx[i];
                t.y += dy[i];
            }
        }
    }
    return 0;
}
int main()
{
	freopen("test", "r", stdin);
    int _;
    scanf("%d",&_);
    while(_--)
    {
        flag = 0;
        scanf("%d%d",&n,&m);
        getchar();
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= m;++j)
                scanf("%c",&s[i][j]);
            getchar();
        }
        scanf("%d%d%d%d%d",&k,&y1,&x1,&y2,&x2);
        if(x1 == x2 && y1 == y2)
        {
            printf("yes\n");
            continue;
        }
        flag = bfs();
        if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

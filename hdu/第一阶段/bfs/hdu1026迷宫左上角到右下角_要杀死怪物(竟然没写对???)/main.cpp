#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#include <vector>
#define MAXN 105
using namespace std;

struct Node {
	int r, c, step, time, dir;
	Node(int _r, int _c, int s, int t) : r(_r), c(_c), step(s), time(t) { 
		dir = 0;
	}
	bool operator < (const Node& other) const {
		return time > other.time;
	}
};

int n, m, dr[]={1,-1,0,0}, dc[]={0,0,1,-1}, vis[MAXN][MAXN];
int dir[]={'d', 'u', 'r', 'l'};
string mtx[MAXN];
int path[MAXN];

bool check(int r, int c, int step) {
	if(r<0 || r>=n || c<0 || c>=m) return false;
	if(step > m*n) return false;
	if(vis[r][c]) return false;
	return true;
}

int bfs() {
	priority_queue<Node> q;
	q.push(Node(0, 0, 0, 0));
	while(!q.empty()) {
		Node x = q.top();
		q.pop();
//		for(int i=0; i<n; i++) {
//			for(int k=0; k<m; k++) {
//				printf("%c ", (i==x.r&&k==x.c) ? '*' : mtx[i][k]);
//			}
//			printf("\n");
//		}
//		printf("\n");
		path[x.step] = x.dir;
		if(x.r==n-1 && x.c==m-1) {
			for(int i=0; i<x.step; i++)
				printf("%c->", path[i]);
			return x.time;
		}
		for(int i=0; i<4; i++) {
			int nr = x.r+dr[i], nc = x.c+dc[i], ns = x.step+1;
			if(!check(nr, nc, ns)) continue;
			char c = mtx[nr][nc];
			int nt = x.time + (c=='.' ? 1 : c-'0');
			Node node(nr, nc, ns, nt);
			node.dir = dir[i];
			q.push(node);
			vis[nr][nc] = true;
		}
	}
	return -1;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		memset(vis, false, sizeof(vis));
		for(int i=0; i<n; i++)
			cin >> mtx[i];
		int rs = bfs();
		printf("---------------%d\n", rs);
	}
	return 0;
}










/**

#include"stdio.h"
#include"string.h"
#include"queue"
using namespace std;
 
struct node
{
	int x,y;
	int step;
	friend bool operator<(node n1,node n2)
	{
		return n2.step<n1.step;
	}
};
int dir[4][2]={0,1, 1,0, 0,-1, -1,0};
int map[111][111];
int flag[111][111];
int blood[111][111];
int n,m;
 
int judge(int x,int y)
{
	if(x<0 || x>=n || y<0 || y>=m)	return 1;
	if(map[x][y]==-1)				return 1;
	return 0;
}
int BFS()
{
	priority_queue<node>q;
	node cur,next;
	int i;
 
	cur.x=0;
	cur.y=0;
	cur.step=0;
	map[0][0]=-1;
 
	q.push(cur);
	while(!q.empty())
	{
		cur=q.top();
		q.pop();
		if(cur.x==n-1 && cur.y==m-1)	return cur.step;
		for(i=0;i<4;i++)
		{
			next.x=cur.x+dir[i][0];
			next.y=cur.y+dir[i][1];
 
			if(judge(next.x,next.y))	continue;
			next.step=cur.step+1+map[next.x][next.y];
			flag[next.x][next.y]=i+1;
			map[next.x][next.y]=-1;
			q.push(next);
		}
	}
	return -1;
}
int temp;
void P(int x,int y)
{
	int next_x,next_y;
	if(flag[x][y]==0)	return ;
	next_x=x-dir[flag[x][y]-1][0];
	next_y=y-dir[flag[x][y]-1][1];
	P(next_x,next_y);
	printf("%ds:(%d,%d)->(%d,%d)\n",temp++,next_x,next_y,x,y);
 
	while(blood[x][y]--)	printf("%ds:FIGHT AT (%d,%d)\n",temp++,x,y);
}
 
int main()
{
	freopen("test", "r", stdin);
	char str[111];
	int i,l;
	int ans;
 
	while(scanf("%d%d",&n,&m)!=-1)
	{
		memset(map,0,sizeof(map));
		memset(flag,0,sizeof(flag));
		memset(blood,0,sizeof(blood));
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			for(l=0;str[l];l++)
			{
				if(str[l]=='.')		map[i][l]=0;
				else if(str[l]=='X')map[i][l]=-1;
				else				map[i][l]=blood[i][l]=str[l]-'0';
			}
		}
 
		ans=BFS();
		if(ans==-1)	printf("God please help our poor hero.\n");
		else
		{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
 
			temp=1;
			P(n-1,m-1);
		}
		printf("FINISH\n");
	}
	return 0;
}
*/


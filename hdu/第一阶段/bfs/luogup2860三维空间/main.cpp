#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 32
using namespace std;

int X, Y, Z;
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
char mtx[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
struct Node {
	int x, y, z, step;
	Node() : step(0) { }
	Node(int _x, int _y, int _z, int _s) : x(_x), y(_y), z(_z), step(_s) { }
} s, e;

int main() {
	freopen("test", "r", stdin);
	scanf("%d %d %d\n", &X, &Y, &Z);
	for(int i=0; i<X; i++) {
		for(int k=0; k<Y; k++) {
			scanf("%s\n", mtx[i][k]);
			for(int j=0; j<Z; j++) 
				if(mtx[i][k][j] == 'S') s.x=i, s.y=k, s.z=j;
				else if(mtx[i][k][j] == 'E') e.x=i, e.y=k, e.z=j;
		}
	}
	queue<Node> q;
	q.push(s);
	while(!q.empty()) {
		Node now = q.front();
		q.pop();
		vis[now.x][now.y][now.z] = true;
		if(now.x==e.x && now.y==e.y && now.z==e.z) {
			printf("Escaped in %d minute(s).\n", now.step);
			return 0;
		}
		for(int i=0; i<6; i++) {
			int nx = now.x+dx[i], ny = now.y+dy[i], nz = now.z+dz[i];
			if(nx<0 || ny<0 || nz<0 || nx>=X || ny>=Y || nz>=Z 
					|| vis[nx][ny][nz] || mtx[nx][ny][nz]=='#')
				continue ;
			q.push(Node(nx, ny, nz, now.step+1));
		}
	}
	printf("Trapped!\n");
	return 0;
}

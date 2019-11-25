#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#define MAXN 12
using namespace std;

string ss, ee;

struct Node {
	int x, y, step;
	Node() : x(0), y(0), step(0) { }
} s, e, x, nx;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool vis[MAXN][MAXN];

bool check(int x, int y) { 
	if(x<1 || x>8 || y<1 || y>8 || vis[x][y]) return false; 
	return true;
}

int bfs() {
	memset(vis, false, sizeof(vis));
	queue<Node> q;
	q.push(s);
	while(!q.empty()) {
		x = q.front();
		q.pop();
		vis[x.x][x.y] = true;
		if(x.x==e.x && x.y==e.y) return x.step;
		for(int i=0; i<8; i++) {
			nx.x = x.x+dx[i], nx.y = x.y+dy[i], nx.step = x.step+1;
			if(check(nx.x, nx.y)) 
				q.push(nx);
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	while( cin >> ss >> ee ) {
		s.step = e.step = 0;
		s.x = ss[0]-'a'+1, s.y = ss[1]-'0';
		e.x = ee[0]-'a'+1, e.y = ee[1]-'0';
		printf("To get from %s to %s takes %d knight moves.\n", ss.data(), ee.data(), bfs());
	}
	return 0;
}

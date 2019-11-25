#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#include <vector>
#define MAXN 55

using namespace std;

int a, b, c, mt, t;
int mtx[MAXN][MAXN][MAXN];
//bool vis[MAXN][MAXN][MAXN];

int di[] = {1, -1, 0, 0, 0, 0};
int dk[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

struct Node {
	int i, k, z, step;
};

queue<Node> q;

bool check(int i, int k, int z) {
	if(i<0||k<0||z<0 || i>=a||k>=b||z>=c) return false;
//	if(mtx[i][k][z]==1 || vis[i][k][z]) return false;
	if(mtx[i][k][z]==0) return true;
	return false;
}

int bfs() {
	Node x, nx;
	x.i = 0, x.k = 0, x.z = 0, x.step = 0;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
		q.pop();
		if(x.i==a-1 && x.k==b-1 && x.z==c-1 && x.step<=mt) return x.step;
	    nx.step = x.step + 1;
		if(nx.step > mt) continue ;
//		vis[x.i][x.k][x.z] = true;
		mtx[x.i][x.k][x.z] = 1;
		for(int i=0; i<6; i++) {
			nx.i = x.i + di[i];
			nx.k = x.k + dk[i];
			nx.z = x.z + dz[i];
			if(check(nx.i, nx.k, nx.z)) {
				if(nx.i==a-1 && nx.k==b-1 && nx.z==c-1 && nx.step<=mt) return nx.step;
				q.push(nx);
				mtx[nx.i][nx.k][nx.z] = 1;
			}
		}
	}
	return -1;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &a, &b, &c, &mt);
		queue<Node> tq;
		q = tq;
		for(int i=0; i<a; i++) 
			for(int k=0; k<b; k++) 
				for(int z=0; z<c; z++) {
//					vis[i][k][z] = false;
					scanf("%d", &mtx[i][k][z]);
				}
		int rs = bfs();
		printf("%d\n", rs);
	}
	return 0;
}


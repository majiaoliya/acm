#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#include <vector>
#define MAXN 32
#define Z(x) ( x==1 ? 0 : 1)

using namespace std;

//char mtx[2][MAXN][MAXN];
//bool vis[2][MAXN][MAXN];
//int t, n, m, mt, pi, pk, si, sk;
//
//int di[] = { 1, -1, 0, 0 };
//int dk[] = { 0, 0, 1, -1 };
//
//struct Node {
//	int z, i, k, step;
//};
//queue<Node> q;
//
//void init() {
//	queue<Node> tq;
//	q = tq;
//}
//
//bool check(int& z, int& i, int& k) {
//	if(i<0 || k<0 || i>n || k>n)
//	   	return false;
//	if(vis[z][i][k])
//	   	return false;
//	if(mtx[z][i][k] == '#' && mtx[Z(z)][i][k] == '#') 
//		return false;
//	if(mtx[z][i][k] == '#' && mtx[Z(z)][i][k] != '*') 
//	   z = Z(z);	
//	if(mtx[z][i][k] == '*')
//		return false;
//	return true;
//}
//
//void bfs() {
//	Node x, nx;
//	x.z=0, x.i=0, x.k=0, x.step=0;
//	q.push(x);
//	while(!q.empty()) {
//		x = q.front();
//		q.pop();
//		vis[x.z][x.i][x.k] = true;
//		if(mtx[x.z][x.i][x.k]=='P' && x.step<=mt) {
//			printf("YES\n", x.step);
//			return ;
//		}
//		for(int i=0; i<4; i++) {
//			nx.step = x.step + 1;
//			if(nx.step > mt) continue ;
//			nx.i=x.i+di[i], nx.k=x.k+dk[i], nx.z=x.z;
//			if(!check(nx.z, nx.i, nx.k)) continue ;
//			q.push(nx);
//		}
//	}
//	printf("NO\n");
//}
//
//int main(void) {
//	freopen("test", "r", stdin);
//	scanf("%d", &t);
//	while(t--) {
//		scanf("%d %d %d", &n, &m, &mt);
//		init();
//		for(int z=0; z<2; z++)
//			for(int i=0; i<n; i++) {
//				scanf("%s", mtx[z][i]);
//				for(int k=0; k<m; k++)
//					if(mtx[z][i][k] == 'P')
//						pi = i, pk = k;
//			}
//		bfs();
//	}
//	return 0;
//}
//

int t, n, m, mt, pi, pk;

char mtx[2][MAXN][MAXN];
bool vis[2][MAXN][MAXN];
int di[] = { 1, -1, 0, 0 };
int dk[] = { 0, 0, 1, -1 };

struct Node {
	int z, i, k, step;
};

queue<Node> q;

void init() {
	queue<Node> tq;
	q = tq;
	memset(vis, false, sizeof(vis));
}

bool check(int& z, int& i, int& k) {
	if(i<0 || k<0 || i>=n || k>=m) return false;
	if(vis[z][i][k]) return false;
	char c = mtx[z][i][k], cc = mtx[Z(z)][i][k];
	if(c == '#') {
		if(cc == '#' || cc == '*') return false;
		z = Z(z);
		return true;
	}
	if(c == '.' || c == 'S' || c == 'P') return true;
	return false;
}

bool bfs() {
	init();
	Node x, nx;
	x.z = 0, x.i = 0, x.k = 0, x.step = 0;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
		q.pop();
//		printf("(%d %d %d step:%d) ", x.z, x.i, x.k, x.step);
		if(mtx[x.z][x.i][x.k]=='P' && x.step<=mt) return true;
		nx.step = x.step + 1;
		if(mtx[x.z][x.i][x.k] != '#')
			vis[x.z][x.i][x.k] = true;
		if(nx.step > mt) continue ;
		for(int i=0; i<4; i++) {
			nx.z = x.z, nx.i = x.i+di[i], nx.k = x.k+dk[i];
			if(check(nx.z, nx.i, nx.k))
				q.push(nx);
		}
	}

	return false;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &n, &m, &mt);
		for(int z=0; z<2; z++)
			for(int i=0; i<n; i++) 
				scanf("%s", mtx[z][i]);
		bool ok = bfs();
//		printf("[%d %d %d]%s\n", n, m, mt, ok ? "YES" : "NO");	
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}


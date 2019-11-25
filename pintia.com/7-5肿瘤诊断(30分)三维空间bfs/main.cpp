////dfs
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <math.h>
//#include <map>
//#include <set>
//#include <string.h>
//#include <algorithm>
//using namespace std;

//int M, N, L, T, gcnt;

//int mtx[64][1300][135]; //mtx[l][r][c]
//bool vis[64][1300][135];

//int dx[6] = {1, 0, 0, -1, 0, 0};
//int dy[6] = {0, 1, 0, 0, -1, 0};
//int dz[6] = {0, 0, 1, 0, 0, -1};

//bool check(int z, int x, int y) {
//	if(z>=0&&z<L && x>=0&&x<M && y>=0&&y<N && mtx[z][x][y]==1) return true;
//	return false;
//}

//void dfs(int z, int x, int y, int& cnt) {
//	if(check(z, x, y) == false) return ;
//	cnt ++;
//	mtx[z][x][y] = 2;
//	for(int i=0; i<6; i++)
//		dfs(z+dz[i], x+dx[i], y+dy[i], cnt);
//}

//int main() {
//	freopen("test", "r", stdin);
//	scanf("%d %d %d %d", &M, &N, &L, &T);
//	for(int z=0; z<L; z++)
//		for(int x=0; x<M; x++)
//			for(int y=0; y<N; y++)
//				scanf("%d", &mtx[z][x][y]);
//	int sum = 0;
//	for(int z=0; z<L; z++)
//		for(int x=0; x<M; x++)
//			for(int y=0; y<N; y++) {
//				if(check(z, x, y) == false) continue;
//				int cnt = 0;
//				dfs(z, x, y, cnt);
//				if(cnt >= T) sum += cnt;
//				printf("%d\n", cnt);
//			}
//	printf("%d", sum);
//	return 0;
//}



//bfs
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int M, N, L, T, gcnt;

int mtx[61][1300][130]; //mtx[l][r][c]

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

bool check(int z, int x, int y) {
	if(z>=0&&z<L && x>=0&&x<M && y>=0&&y<N && mtx[z][x][y]==1) return true;
	return false;
}

struct Node {
	int x, y, z;
	Node() : x(0), y(0), z(0) { }
	Node(int tz, int tx, int ty) : x(tx), y(ty), z(tz) { }
};

void bfs(int z, int x, int y, int& cnt) {
	Node fst;
	fst.z = z, fst.x = x, fst.y = y;
	queue<Node> q;
	q.push(fst);
	while(!q.empty()) {
		Node n = q.front();
		q.pop();
		if(check(n.z, n.x, n.y)) {
			cnt ++;
			mtx[n.z][n.x][n.y] = 2;
			for(int i=0; i<6; i++) {
				int tz = n.z + dz[i], tx = n.x + dx[i], ty = n.y + dy[i];
				Node tn;
				tn.z = tz, tn.x = tx, tn.y = ty;
				if(check(tz, tx, ty))
					q.push(tn);
			}
		}
	}
}

int main() {
	freopen("test", "r", stdin);
	scanf("%d %d %d %d", &M, &N, &L, &T);
	for(int z=0; z<L; z++)
		for(int x=0; x<M; x++)
			for(int y=0; y<N; y++)
				scanf("%d", &mtx[z][x][y]);
	int sum = 0;
	for(int z=0; z<L; z++)
		for(int x=0; x<M; x++)
			for(int y=0; y<N; y++) {
				if(check(z, x, y) == false) continue;
				int cnt = 0;
				bfs(z, x, y, cnt);
				if(cnt >= T) sum += cnt;
			}
	printf("%d", sum);
	return 0;
}


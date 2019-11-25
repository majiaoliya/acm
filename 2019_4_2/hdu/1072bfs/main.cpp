#include <iostream>
#include <queue>
#include <vector>
#define MAX 16
using namespace std;

struct Node {
	int r, c, step, time;
	Node() {}
	Node(int _r, int _c, int _s, int _t) : r(_r), c(_c), step(_s), time(_t) { };
};

int r, c;
int start_r, start_c;

int mtx[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs() {
	queue<Node> q;
	Node n(start_r, start_c, 0, 6);
	q.push(n);
	while(!q.empty()) {
		Node x = q.front();
		Node t;
		q.pop();
		for(int i=0; i<4; i++) {
			t.r = x.r + dr[i];
			t.c = x.c + dc[i];
			t.step = x.step + 1;
			t.time = x.time - 1;
			if(t.r>=0&&t.r<r && t.c>=0&&t.c<c && t.time>0 && mtx[t.r][t.c]!=0) {
				if(mtx[t.r][t.c] == 3) {
					printf("%d\n", t.step);
					return ;
				}
				if(mtx[t.r][t.c] == 4) {
					t.time = 6;
					mtx[t.r][t.c] = 0;
				}
				q.push(t);
			}
		}
	}
	printf("%d\n", -1);
}

int main() {
	freopen("test", "r", stdin);
	
	int n;
	scanf("%d", &n);
	for( ; n--; ) {
		scanf("%d %d", &r, &c);
		for(int i=0; i<r; i++) {
			for(int k=0; k<c; k++) {
				scanf("%d", mtx[i]+k);
				if(mtx[i][k] == 2) start_r = i, start_c = k;
			}
		}
		bfs();		
	}
	
	return 0;
}

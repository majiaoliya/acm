#include <iostream>
#include <queue>
#define MAX 205
using namespace std;

struct Node {
	int r, c, step;
	Node() { }
	Node(int _r, int _c, int _step) : r(_r), c(_c), step(_step) { }
};

char mtx[MAX][MAX];
int r, c;
int start_r, start_c;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs() {
	queue<Node> q;
	Node n(start_r, start_c, 0);
	q.push(n);
	vector<int> rs;
	while(!q.empty()) {
		Node x = q.front();
		Node t;
		q.pop();
		for(int i=0; i<4; i++) {
			t.r = x.r + dr[i];
			t.c = x.c + dc[i];
			t.step = x.step + 1;
			if(t.r>=0&&t.r<r && t.c>=0&&t.c<c && mtx[t.r][t.c]!='#') {
				if(mtx[t.r][t.c] == 'r') { //遇上朋友
					rs.push_back(t.step);
				}
				if(mtx[t.r][t.c] == 'X') { //遇上守卫
					mtx[t.r][t.c] = '.';
					t.step += 1; //额外花费的时间
				}
				q.push(t);
			}
		}
		printf("%d,%d\n", t.r, t.c);
	}
	for(int i=0, c=0; i<rs.size(); i++) {
		if(c++) printf(" ");
		printf("%d", rs[i]);
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &r, &c); ) {
		cin.ignore();
		for(int i=0; i<r; i++) {
			cin.getline(mtx[i], MAX);
			for(int k=0; k<c; k++) 
				if(mtx[i][k] == 'a') start_r = i, start_c = k;
		}
		bfs();
	}
	
	return 0;	
}

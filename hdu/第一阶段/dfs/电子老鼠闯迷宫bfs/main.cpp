#include <iostream>
#include <queue>
using namespace std;
 
struct Node {
	int row, col, step;
	Node() { }
	Node(int r, int c, int s) : row(r), col(c), step(s) { }
};
 
int n;
int s_row, s_col, e_row, e_col;

char mtx[15][15];
bool vis[15][15];	
int min_step = 13*13;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void bfs() { //bfs可以找到一条最短的路径(找到第一条就return)
	Node n(s_row, s_col, 0);
	queue<Node> q;
	q.push(n);
	while(!q.empty()) {
		Node x = q.front(); q.pop();
		vis[x.row][x.col] = true;
		for(int i=0; i<4; i++) {
			Node next(x.row+dr[i], x.col+dc[i], x.step+1);
			if(next.row>=1 && next.row<=12 && next.col>=1 && next.col<=12) {
				if(next.row==e_row && next.col==e_col) { //到终点
					printf("find:%d\n", next.step);
					return;
				} else if(mtx[next.row][next.col]!='X' && !vis[next.row][next.col]) {
					q.push(next);
				}
			}
		}
	}
	printf("can not find!\n");
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d %d %d", &s_row, &s_col, &e_row, &e_col);
	cin.ignore();
	for(int i=1; i<=12; i++) {
		cin.getline(mtx[i]+1, 15);
		cout << mtx[i]+1 << endl;
	}
	cout << endl;
	bfs();
	
	return 0;
}

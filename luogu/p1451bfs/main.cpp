#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define MAXN 128

char mtx[MAXN][MAXN];
int row, col;

struct Node {
	int r, c;
	Node(int _r, int _c) : r(_r), c(_c) { }
};
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

void bfs(int r, int c) {
	if(mtx[r][c] == '0') return ;
	queue<Node> q;
	q.push(Node(r, c));
	while(!q.empty()) {
		Node now = q.front();
		q.pop();
		mtx[now.r][now.c] = '0';
		for(int i=0; i<4; i++) {
			int nr = r+dr[i], nc = c+dc[i];
			if(nr>=0 && nc>=0 && nr<row && nc<col && mtx[nr][nc]!='0')
				q.push(Node(nr, nc));
		}
	}
}

void dfs(int r, int c) {
	if(mtx[r][c] == '0') return ;
	mtx[r][c] = '0';
	for(int i=0; i<4; i++) {
		int nr = r+dr[i], nc = c+dc[i];
		if(nr>=0 && nc>=0 && nr<row && nc<col && mtx[nr][nc]!='0')
			dfs(nr, nc);
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d\n", &row, &col);
	for(int i=0; i<row; i++)
		scanf("%s\n", mtx[i]);
	int ans = 0;
	for(int i=0; i<row; i++)
		for(int k=0; k<col; k++)
			if(mtx[i][k] != '0') ans++, dfs(i, k);
	printf("%d\n", ans);
	return 0;
}




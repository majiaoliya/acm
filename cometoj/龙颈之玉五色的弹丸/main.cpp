#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long int
const int MAXN = 405;
int n, m;
int dir[256];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };
char mtx[MAXN][MAXN];
char str[100005];

struct Node {
	int r, c;
	Node() : r(0), c(0) { }
	Node(int _r, int _c) : r(_r), c(_c) { }
} ;

deque<Node> q;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d\n", &n, &m);
	int r = 0, c = 0;
	for(int i=0; i<n; i++) {
		scanf("%s\n", mtx[i]);
		for(int k=0; k<m; k++) 
			if(mtx[i][k] == '@') {
				r = i, c = k;
				mtx[i][k] = '.';
				q.push_back(Node(i, k));
			}
	}
	dir[(int)'W'] = 0, dir[(int)'A'] = 1, dir[(int)'S'] = 2, dir[(int)'D'] = 3;
	scanf("%s\n", str);
	bool die = false;
	for(int i=0; str[i]; i++) {
		int id = dir[(int)str[i]];
		int nr = r+dr[id], nc = c+dc[id];
		if(nr<0 || nc<0 || nr>=n || nc>=m) {
			die = true;
			break;
		}
		if(mtx[nr][nc] == '.') {
			q.push_front(Node(nr, nc));
			q.pop_back();
		} else if(mtx[nr][nc] == 'o') {
			q.push_front(Node(nr, nc));
			mtx[nr][nc] = '.';
		}
		r = nr, c = nc;
	}
	if(die) {
		printf("GG\n");
		return 0;
	}
	for( ; !q.empty(); q.pop_front())
		mtx[q.front().r][q.front().c] = 'X';
	mtx[r][c] = '@';
	for(int i=0; i<n; i++)
		printf("%s\n", mtx[i]);
	return 0;
}

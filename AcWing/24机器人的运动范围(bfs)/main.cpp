#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug

typedef vector<vector<bool> > vvis;

struct Node {
	int step, r, c;
} ;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

class Solution {
public:
	int row, col, k;
    int movingCount(int kk, int rows, int cols) {
		if(!(rows+cols)) return 0;
		row = rows, col = cols, k = kk;
		vvis vis(rows, vector<bool>(cols, false));
		return bfs(vis);
    }

	int sumit(int r, int c) {
		int sum = 0;
		while(r) sum+=r%10, r/=10;
		while(c) sum+=c%10, c/=10;
		return sum;
	}
	inline bool check(int r, int c) { return (r>=0 && r<row && c>=0 && c<col && sumit(r, c)<=k); }

	int bfs(vvis& vis) {
		queue<Node> q;
		Node x, nx;
		x.r = x.c = x.step = 0;
		q.push(x);
		int ret = 0;
		while(!q.empty()) {
			x = q.front(); q.pop();
			if(!vis[x.r][x.c]) ret++;
			else continue ;
			vis[x.r][x.c] = true;
			for(int i=0; i<4; i++) {
				nx.r = x.r+dr[i], nx.c = x.c+dc[i];
				if(check(nx.r, nx.c) && !vis[nx.r][nx.c]) q.push(nx);
			}
		}
		return ret;
	}
};

#ifdef debug
int main(void) {
	Solution s;
	int k = 7, m = 4, n = 5;
	printf("%d\n", s.movingCount(k, m, n));
	return 0;
}
#endif

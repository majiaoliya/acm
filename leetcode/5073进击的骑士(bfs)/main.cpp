#define ll long long int
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
#include <string>
#define abs(x) (x > 0 ? x : -x)
#define MAXN (302)
using namespace std;

struct Node {
	int x, y, step;
	Node() : x(0), y(0), step(0) { }
	Node(int _x, int _y, int _s) : x(_x), y(_y), step(_s) { }
} ;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

class Solution {
public:
    int minKnightMoves(int xx, int yy) {
		queue<Node> q;
		Node x, nx;
		q.push(x);
		int ret = -1;
		while(!q.empty()) {
			x = q.front();
			q.pop();
			if(x.x==abs(xx) && x.y==abs(yy)) { ret = x.step; break; }
			for(int i=0; i<8; i++) { //广搜8个方向
				nx.x = x.x+dx[i], nx.y = x.y+dy[i];
				if(nx.x<0 || nx.y<0 || nx.x>MAXN || nx.y>MAXN) continue ; //剪掉非第一象限
				nx.step = x.step + 1;
				q.push(nx);
			}
		}
		return ret;
    }
};
#define debug
#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	Solution s;
	cout << s.minKnightMoves(2, 1) << endl;
	cout << s.minKnightMoves(5, 5) << endl;
	return 0;
}
#endif

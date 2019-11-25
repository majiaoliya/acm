/**
 * https://blog.csdn.net/XxxxxM1/article/details/82255383
 * The competition is going. Besides the players, volunteers are busy too,
	  they need to send colorful balloons to the contestants. It is known that the contestants are in a huge room of cartesian coordinate system whose seats are 1000 rows multiplying 1000 columns. Every seat could be empty or corresponds to a team. For every minute, volunteers should send all the balloons together. The volunteers will be told where to send each balloon to. They would like to work efficiently. For two positions (r1, c1) and (r2, c2), if the absolute value of (x1 - x2) is not bigger than k or the absolute value of (y1 – y2) is not bigger than k, the two balloons will be sent by a same volunteer. Could you decide how many volunteers are needed at least to send all the balloons?
 */



#include <iostream>
#include <algorithm>
#define MAXN 1005
using namespace std;

int abs(int x) { return x > 0 ? x : -x; }

struct Node {
	int row, col;
	Node() : row(0), col(0) { }
};

Node arr[MAXN];
int pre[MAXN];

bool check(Node& x, Node& y, int k) {
	int abs_row = abs(x.row-y.row);
	int abs_col = abs(x.col-y.col);
	if(abs_col<=k || abs_row<=k) return true;
	return false;
}

int find_root(int x) {
	int ret = x;
	while(pre[ret] != -1) 
		ret = pre[ret];
	if(ret != x) 
		pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int root_x = find_root(x);
	int root_y = find_root(y);
	if(root_x != root_y) 
		pre[root_y] = root_x;
}

int main(void) {
	
	freopen("test", "r", stdin);
	
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; i++) {
			pre[i] = -1;
		}
		for(int i=0; i<n; i++) {
			scanf("%d %d", &(arr[i].row), &(arr[i].col));
			for(int j=0; j<i; j++) {
				if(check(arr[i], arr[j], k)) {
					union_xy(i, j);
				}
			}
		}
		int count = 0;
		for(int i=0; i<n; i++) 
			if(pre[i] == -1) count ++;
		printf("%d\n", count);
	}
		
	return 0;
}

#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 10
using namespace std;

int n, mtx[MAXN][MAXN];

struct Node {
	int x, y;
} node;
vector<Node> v;

void dsp() {
	for(int i=0; i<9; i++) {
		for(int k=0; k<9; k++) {
			if(k) printf(" ");
			printf("%d", mtx[i][k]);
		}
		printf("\n");
	}
}

bool check(int x, int y, int val) {
	for(int i=0; i<9; i++)
		if(mtx[x][i] && mtx[x][i]==val) return false;
	for(int i=0; i<9; i++)
		if(mtx[i][y] && mtx[i][y]==val) return false;
	for(int i=x/3*3; i<(x/3*3)+3; i++)
		for(int k=y/3*3; k<(y/3*3)+3; k++)
			if(mtx[i][k] && mtx[i][k]==val) return false;
	return true;
}

void dfs(int pos) {
	if(pos >= v.size()) {
		dsp();
		return ;
	}
	for(int i=1; i<=9; i++) {
		int x = v[pos].x, y = v[pos].y;
		if(check(x, y, i)) {
			mtx[x][y] = i;
			dfs(pos+1);
			mtx[x][y] = 0;
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	char c;
	int cases = 0;
	do {
		v.clear();
//		printf("case %d:\n", cases++);
//		memset(mtx, false, sizeof(mtx));
		for(int i=0; i<9; i++) 
			for(int k=0; k<9; k++) {
				scanf("%c", &c);
				getchar();
				if(c != '?') mtx[i][k] = c-'0';
				else {
					node.x = i, node.y = k;
					v.push_back(node);
					mtx[i][k] = 0;
				}
			}
//		dsp();
		if(cases++)
			printf("\n");
		dfs(0);
	} while(~scanf("%c", &c));
	return 0;
}

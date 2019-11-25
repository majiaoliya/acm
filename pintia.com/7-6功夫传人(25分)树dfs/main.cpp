#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n, fangda[MAXN];
double z, bfb, sum; //祖师爷功力,和下降百分比

vector<int> G[MAXN];

void dsp() {
	for(int i=0; i<n; i++) {
		cout << i << ":";
		for(int k=0; k<G[i].size(); k++)
			cout << G[i][k] << ",";
		cout << endl;
	}
}

void dfs(int x, double x_gong) { //得道者都在叶子节点????
//	printf("fangda[%d] = %d\n", x, fangda[x]);
	if(G[x].empty()) {
		sum += x_gong*fangda[x];
//		printf("%d是得道者 %lf被放大%d = %lf\n ", x, x_gong, fangda[x], 
//			x_gong*fangda[x]);
		return ;
	}
	for(int i=0; i<G[x].size(); i++) {
		double chl_gong = x_gong - x_gong*bfb;
		int chl = G[x][i];
		dfs(chl, chl_gong);
	}
}

int main() {
	freopen("test", "r", stdin);
	
	cin >> n >> z >> bfb;
	bfb /= 100;
	for(int i=0; i<n; i++) {
		int t, x;
		cin >> t;
		if(t == 0) {
			cin >> x; //得道者放大倍数
			fangda[i] = x;
		} else {
			for(int k=1; k<=t; k++) {
				cin >> x;
				G[i].push_back(x);
			}
		}
	}
//	dsp();
	dfs(0, z);
	printf("%d\n", (int)sum);
	return 0;
}



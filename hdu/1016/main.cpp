#include <iostream>
#include <vector>
using namespace std;

bool isSS(int x) { //判断是否是素数
	bool ret = true;
	for(int i=2; i<x; i++) {
		if(x/i == 0) ret = false;
	}
	return ret;
}

bool dfs(bool* isPut, int vn, std::vector<int>& rs,  int x, int x_index) {
	if(isPut !isSS(rs[x_index-1] + x) ) return false;
	isPut[x_index]
}

int main(void) {
	
	int n;
	for( ; cin>>n, n; ) {
		int i=2;
		std::vector<int> rs; rs.push_back(0), rs.push_back(1);
		bool isPut[n+1]; //是否在圆环内
		memset(isPut, 0, sizeof(visit)/sizeof(visit[0]));
		isPut[1] = true;
		for( ; i<=n; i++) {
			if(isSS(i) && isSS(rs[i-1]+i)) {

			}
		}
	}

	return 0;
}

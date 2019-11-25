#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <unordered_set>
#define ll long long int
#define max(x, y) ( x > y ? x : y )
#define min(x, y) ( x < y ? x : y )
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

int n, m, q, arr[MAXN], psum[MAXN];
int mtx[MAXN][MAXN];

inline int get_cnt(int lef, int rig) {
	int cnt = 0;
/**
	map<int, int> mp;
	for( ; lef<=rig; lef++) {
		int& rx = mp[arr[lef]];
		if(rx == 0) cnt ++;
		rx ++;
	}
*/
	return cnt;
}

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		for(int i=1; i<=n; i++) 
			scanf("%d", arr+i);
		map<int, int> mp;
		// mtx[L][R] = 区间[L,R]的数
		for(int i=1; i<=n; i++) {
			unordered_set<int> seta;		
			seta.insert(arr[i]);
			for(int k=i; k<=n; k++) {
				seta.insert(arr[k]);
				mtx[i][k] = seta.size();
			}
		}
#ifdef debug
		for(int i=1; i<=n; i++) {
			for(int k=1; k<=n; k++) {
				printf("%d ", mtx[i][k]);
			}
			printf("\n");
		}
#endif
		int L, R;
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d", &L, &R);
			printf("%d\n", mtx[L][R]);
		}
	}
	return 0;
}




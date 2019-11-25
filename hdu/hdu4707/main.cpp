#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n, dist;

int pre[MAXN], level[MAXN];
bool vis[MAXN];

int main(void) {
	
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d %d", &n, &dist);
		memset(vis, false, sizeof(vis));
		memset(level, false, sizeof(level));
		int par, chl, rs = 0;
		for(int i=0; i<n-1; i++) {
			scanf("%d %d", &par, &chl);
			pre[chl] = par;
		}
		pre[0] = -1;
		vis[0] = true;
		level[0] = 1;
		vector<int> pres;
		for(int i=1; i<n; i++) {
			pres.clear();
			int chl_id = i, par_id = pre[i], count=1;
			while(par_id != -1) {
				if(vis[par_id]) {
					count += level[par_id];
					break;
				}
				pres.push_back(par_id);
				chl_id = par_id;
				par_id = pre[par_id];
				count ++;
			}
			vis[i] = true;
			level[i] = count;
			if(count > dist+1) rs ++; //超过距离 更新结果
			
			for(int k=0, t=count; k<pres.size(); k++) {
				int temp = pres[k];
				vis[temp] = true;
				level[temp] = --t;
				if(t > dist+1) rs ++; //超过距离 更新结果
			}
		}
//		for(int i=0; i<n; i++) {
//			printf("%d,", level[i]);
//		}
		printf("%d\n", rs);
	}

	return 0;
}

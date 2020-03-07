#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 205;
vector<pair<int, int> > E[maxn];

int d[maxn];
int n, m;

void init() {
	for(int i=0; i<maxn; i++) {
		E[i].clear();
		d[i] = 1e9;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	
	while(cin >> n >> m) {
		init();
		for(int i=0; i<m; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			E[x].push_back(make_pair(y, z));
			E[y].push_back(make_pair(x, z));
		}
		int s, t;
		scanf("%d %d", &s, &t);
		priority_queue<pair<int, int> > Q;
		Q.push(make_pair(-d[s],s)), d[s] = 0;
		while(!Q.empty()) { //dijkstra+堆优化
			int now = Q.top().second;
			Q.pop();
			for(int i=0; i<(int)E[now].size(); i++) {
				int v = E[now][i].first;
				if(d[v] > d[now]+E[now][i].second) { //松弛
					d[v] = d[now] + E[now][i].second;
					Q.push(make_pair(-d[v], v));
				}
			}
		}

		if(d[t] == 1e9) printf("-1\n");
		else printf("%d\n", d[t]);
	}
	
	return 0;
}

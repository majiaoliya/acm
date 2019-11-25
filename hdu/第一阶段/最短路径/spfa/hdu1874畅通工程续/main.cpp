#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 205;
vector<pair<int, int> > E[maxn];

int d[maxn];
int inq[maxn], n, m;

void init() {
	for(int i=0; i<maxn; i++) {
		E[i].clear();
		inq[i] = 0;
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
		queue<int> Q;
		Q.push(s), d[s] = 0, inq[s] = true;
		while(!Q.empty()) {
			int now = Q.front();
			Q.pop();
			inq[now] = 0;
			for(int i=0; i<(int)E[now].size(); i++) {
				int v = E[now][i].first;
				if(d[v] > d[now]+E[now][i].second) { //松弛
					d[v] = d[now] + E[now][i].second;
					if(inq[v] == 1) continue ; //已在队列里就continue
					inq[v] = 1;
					Q.push(v);
				}
			}
		}

		if(d[t] == 1e9) printf("-1\n");
		else printf("%d\n", d[t]);
	}
	
	return 0;
}

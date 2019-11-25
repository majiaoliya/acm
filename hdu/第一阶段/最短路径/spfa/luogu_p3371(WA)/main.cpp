#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define OO (2147483647)
#define ll long long
const ll MAXN = 1e5+2;

struct Edge {
	ll to, val;
	Edge() : to(0), val(0) { }
	Edge(ll _to, ll _val) : to(_to), val(_val) { }
} ;

vector<Edge> E[MAXN];

ll d[MAXN], inq[MAXN], n, m, s;
inline void init() {
	for(int i=1; i<=n; i++)
		E[i].clear(), d[i] = OO, inq[i] = false;
}

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%lld %lld %lld", &n, &m, &s) ) {
		init();
		for(int i=1; i<=m; i++) {
			ll x, y, val;
			scanf("%lld %lld %lld", &x, &y, &val);
			E[x].push_back(Edge(y, val));
			E[y].push_back(Edge(x, val));
		}
		queue<ll> q;
		q.push(s), d[s] = 0, inq[s] = true;
		while(!q.empty()) {
			ll now = q.front();
			q.pop();
			inq[now] = false;
			for(int i=0; i<(ll)E[now].size(); i++) {
				ll v = E[now][i].to;
				if(d[v] > d[now]+E[now][i].val) {
					d[v] = d[now]+E[now][i].val;
					if(inq[v]) continue ;
					inq[v] = true;
					q.push(v);
				}
			}
		}
		for(int i=1; i<=n; i++)
			printf("%lld%c", d[i], i==n ? '\n' : ' ');
	}
	
	return 0;
}

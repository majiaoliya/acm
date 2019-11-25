#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int> > vvi;
#define INF (1<<30)
struct Edge {
	int to, val;
	Edge() : to(-1), val(INF) { }
	Edge(int _to, int _val) : to(_to), val(_val) { }
} ;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        bool vis[N+1] = { 0 };
		vector<int> d(N+1, INF);
		vector<Edge> G[N+1];
		for(auto x : times)
			G[x[0]].push_back(Edge(x[1], x[2]));
		//spfa
		queue<int> q;
		q.push(K), vis[K] = true, d[K] = 0;
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			vis[now] = false;
			for(int i=0; i<(int)G[now].size(); i++) {
				int v = G[now][i].to, td = G[now][i].val;
				if(d[v] > d[now]+td) {
					d[v] = d[now]+td;
					if(vis[v]) continue;
					q.push(v);
					vis[v] = true;
				}
			}
		}
		int ans = -1;
		for(int i=1; i<=N; i++)
			if(d[i] == INF) return -1;
			else ans = max(ans, d[i]);
		return ans;
	}
};


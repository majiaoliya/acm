#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100005
#include <map>
#include <unordered_set>
#include <queue>
#include <stack>
#define ll long long int
#define INF (1<<30)

using namespace std;

int n, m, T[MAXN], D[MAXN], S, E, vis[MAXN], cntT[MAXN], cntD[MAXN];
int preT[MAXN], preD[MAXN];

struct Edge {
	int to, tim, len;
	Edge(int _to, int _tim, int _len) : to(_to), tim(_tim), len(_len) { }
} ;

vector<Edge> G[MAXN];

void spfaT() {
	for(int i=0; i<n+3; i++)
		vis[i] = false, T[i] = INF, preT[i] = -1;
	queue<int> q;
	q.push(S), vis[S] = true, T[S] = 0;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		vis[now] = false;
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to, td = G[now][i].tim;
			if(T[v] > T[now]+td) {
				T[v] = T[now]+td;
				preT[v] = now;
				cntT[v] = cntT[now]+G[now][i].len;
				if(vis[v]) continue ;
				vis[v] = true;
				q.push(v);
			} else if(T[v] == T[now]+td) {
				if(cntT[v] > cntT[now]+G[now][i].len) {
					preT[v] = now;
					cntT[v] = cntT[now]+G[now][i].len;
					if(vis[v]) continue ;
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

void spfaD() {
	for(int i=0; i<n+3; i++)
		vis[i] = false, D[i] = INF, preD[i] = -1, cntD[i] = INF;
	queue<int> q;
	q.push(S), vis[S] = true, D[S] = 0;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		vis[now] = false;
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to, td = G[now][i].len;
			if(D[v] > D[now]+td) {
				D[v] = D[now]+td;
				preD[v] = now;
				cntD[v] = cntD[now]+1;
				if(vis[v]) continue ;
				vis[v] = true;
				q.push(v);
			} else if(D[v] == D[now]+td) {
				if(cntD[v] > cntD[now]+1) {
					preD[v] = now;
					cntD[v] = cntT[now]+1;
					if(vis[v]) continue ;
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

void printit() {
	vector<int> st, sd;
	int now = E;
	while(preT[now] != -1) {
		st.push_back(now);
		now = preT[now];
	}
	now = E;
	while(preD[now] != -1) {
		sd.push_back(now);
		now = preD[now];
	}
	st.push_back(S), sd.push_back(S);
	bool ok = true;
	for(int i=0; i<st.size() && i<sd.size(); i++)
		if(st[i] != sd[i]) { ok = false; break; }
	if(st.size() != sd.size()) ok = false;
	if(ok) {
		printf("Time = %d; Distance = %d:", T[E], D[E]);
		for(int i=st.size()-1; i>=0; i--) {
			printf(" %d%s", sd[i], i?" ":"");
			if(i) printf("=>");
		}
		return ;
	}
	printf("Time = %d:", T[E]);
	for(int i=st.size()-1; i>=0; i--) {
		printf(" %d%s", st[i], i?" ":"");
		if(i) printf("=>");
	}
	printf("\n");
	printf("Distance = %d:", D[E]);
	for(int i=sd.size()-1; i>=0; i--) {
		printf(" %d%s", sd[i], i?" ":"");
		if(i) printf("=>");
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=0; i<m; i++) {
		int u, v, tag, len, tim;
		scanf("%d %d %d %d %d ", &u, &v, &tag, &len, &tim);
		G[u].push_back(Edge(v, tim, len));
		if(!tag) G[v].push_back(Edge(u, tim, len));
	}
	scanf("%d %d ", &S, &E);
	spfaT();
	spfaD();
	printit();
	//int now = E;
	//printf("time:%d  %d, ", T[E], now);
	//while(preT[now] != -1) {
	//	printf("%d, ", preT[now]);
	//	now = preT[now];
	//}
	//printf("\n");
	//now = E;
	//printf("%d, ", now);
	//while(preD[now] != -1) {
	//	printf("%d, ", preD[now]);
	//	now = preD[now];
	//}

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


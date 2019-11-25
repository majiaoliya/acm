#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#define MAXN 505
#define OO 999999
using namespace std;

int n, m, s, e;
int mtx[MAXN][MAXN], cost[MAXN][MAXN];
void dsp() {
	for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++) {
			printf("%d\t", mtx[i][k]);
		}
		printf("\n");
	}
}

void djk() {
	int dist[n], pre[n], tc[n], vis[n];
	for(int i=0; i<n; i++) {
		vis[i] = false;
		dist[i] = mtx[s][i];
		tc[i] = cost[s][i];
		pre[i] = dist[i]==OO ? -1 : s;
	}
	vis[s] = true;
	
	for(int i=0; i<n; i++) {
		int min = OO, min_id = s;
		for(int k=0; k<n; k++) {
			if(!vis[k] && dist[k]<min) {
				min = dist[k];
				min_id = k;
			}
		}
		vis[min_id] = true;
		for(int k=0; k<n; k++) {
			int t = mtx[min_id][k] + dist[min_id];
			if(!vis[k] && t<dist[k]) {
				dist[k] = t;
				pre[k] = min_id;
				tc[k] = cost[min_id][k] + tc[min_id];
			} else if(!vis[k] && t==dist[k]) {
				int kc = cost[min_id][k] + tc[min_id];
				if(kc < tc[k]) {
					pre[k] = min_id;
					tc[k] = kc;
				}
			}
		}
	}
	stack<int> stk;
	int idx = e, c = 0;
	while(idx != -1) {
		stk.push(idx);
		idx = pre[idx];
	}
	while(!stk.empty()) {
		printf("%d ", stk.top());
		stk.pop();
	}
	printf("%d %d\n", dist[e], tc[e]);
	
//	for(int k=0; k<n; k++) 
//		printf("%d,", dist[k]);
//	printf("\n");
//	for(int k=0; k<n; k++) 
//		printf("%d,", tc[k]);
//	printf("\n");
//	for(int k=0; k<n; k++) 
//		printf("%d,", pre[k]);
}

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d %d %d %d", &n, &m, &s, &e);
	for(int i=0; i<n; i++) 
		for(int k=0; k<n; k++)
			mtx[i][k] = cost[i][k] = OO; 
	for(int i=1; i<=m; i++) {
		int x, y, d, c;
		scanf("%d %d %d %d", &x, &y, &d, &c);
		mtx[x][y] = mtx[y][x] = d;
		cost[x][y] = cost[y][x] = c;
	}
//	dsp();
	djk();
	
	return 0;
}

























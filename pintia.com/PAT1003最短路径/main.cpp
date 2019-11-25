
#include <iostream>
#include <limits.h>
#define MAXN 505
#define OO 999999999
using namespace std;

int n, m, s, e;
int val[MAXN];
int mtx[MAXN][MAXN];

//void djk() {
//	int dist[n], way_count[n], value[n];
//	bool vis[n];
//	for(int i=0; i<n; i++) {
//		vis[i] = false;
//		dist[i] = mtx[s][i];
//		if(dist[i] != OO) {
//			way_count[i] = 1;
//			value[i] = val[s] + val[i];
//		} else {
//			way_count[i] = 0;
//			value[i] = 0;
//		}
//	}
//	vis[s] = true;
//	way_count[s] = 1;
//	value[s] = val[s];
//	for(int i=0; i<n; i++) {
//		if(vis[i]) continue ;
//		int min = OO, min_id = s;
//		for(int k=0; k<n; k++) {
//			if(!vis[k] && min>dist[k]) {
//				min = dist[k];
//				min_id = k;
//			}
//		}
//		vis[min_id] = true;
//		for(int k=0; k<n; k++) {
//			int td = mtx[min_id][k] + dist[min_id];
//			if(!vis[k] && td<dist[k]) { //发现最短路径
//				dist[k] = td;
//				way_count[k] = 1;
//				value[k] = value[min_id] + val[k];
//			} else if(!vis[k] && td==dist[k]) {
//				way_count[k] ++;
//				int tv = value[min_id] + val[k];
//				if(tv > value[k])
//					value[k] = tv;
//			}
//		}
//	}
//	printf("%d %d\n", way_count[e], value[e]);
//}

void djk() {
	int dist[n], value[n], ways[n];
	bool vis[n];
	for(int i=0; i<n; i++) {
		vis[i] = false;
		dist[i] = mtx[s][i];
		if(dist[i] != OO) {
			value[i] = val[s] + val[i];
			ways[i] = 1;
		} else {
			value[i] = 0;
			ways[i] = 0;
		}
	}
	vis[s] = true;
	ways[s] = 1;
	value[s] = val[s];
	for(int i=0; i<n; i++) {
		int min = OO, min_id = s;
		for(int k=0; k<n; k++) {
			if(!vis[k] && min>dist[k]) {
				min = dist[k];
				min_id = k;
			}
		}
		vis[min_id] = true;
		for(int k=0; k<n; k++) {
			int t = dist[min_id] + mtx[min_id][k];
			if(!vis[k] && t<dist[k]) { //发现最短路径
				dist[k] = t;
				value[k] = value[min_id] + val[k];
				ways[k] = ways[min_id];e
			} else if(!vis[k] && t==dist[k]) { //发现相同路径
				int tv = value[min_id] + val[k];
				ways[k] += ways[min_id]; //更新路径条数
				if(tv > value[k]) //如果价值更大
					value[k] = tv; //更新
			}
		}
	}
	printf("%d %d\n", ways[e], value[e]);
}

int main() {
	freopen("test", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &s, &e);
	for(int i=0; i<n; i++)
		for(int k=0; k<n; k++)
			mtx[i][k] = OO;
	for(int i=0; i<n; i++)
		scanf("%d", val+i);
	for( ; m--; ) {
		int x, y, d;
		scanf("%d %d %d", &x, &y, &d);
		mtx[x][y] = mtx[y][x] = d;
	}
	
	djk();
	
	return 0;
}

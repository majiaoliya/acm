#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#define OO 99999999
#define MAX 1005

using namespace std;

vector<int> startv, endv;

int t, s, d, n;
int mtx[MAX][MAX];
int min_dist[MAX];

void djk(int st) {
	bool vis[n+1];
	int dist[n+1];
	for(int i=1; i<=n; i++) {
		vis[i] = false;
		dist[i] = mtx[st][i];
	}

	vis[st] = true;
	for(int i=1; i<=n; i++) {
		int min = OO, min_id = st;
		for(int k=1; k<=n; k++) {
			if(!vis[k] && dist[k]<min) {
				min = dist[k];
				min_id = k;
			}
		}
		vis[min_id] = true;
		for(int k=1; k<=n; k++) {
			int t = mtx[min_id][k] + dist[min_id];
			if(!vis[k] && t<dist[k]) {
				dist[k] = t;
			}
		}
	}
	for(int i=1; i<=n; i++)
		if(min_dist[i] > dist[i]) min_dist[i] = dist[i];
	//for(int i=1; i<=n; i++)
	//	printf("%d,", min_dist[i]);
	//printf("\n");
}

void dsp() {
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=n; k++) {
			if(mtx[i][k] == OO) 
				printf("*\t");
			else
				printf("%d\t", mtx[i][k]);
		}
		printf("\n");
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d %d", &t, &s, &d);
//	for( ; n=0, EOF != scanf("%d %d %d", &t, &s, &d); ) {
		for(int i=0; i<MAX; i++)
			for(int k=0; k<MAX; k++)
				mtx[i][k] = OO;
		for(int i=0; i<MAX; i++) {
			min_dist[i] = OO;
		}
		for(int i=0; i<t; i++) {
			int x, y, time;
			scanf("%d %d %d", &x, &y, &time);
			n = x > n ? x : n;
			n = y > n ? y : n;
		//	printf("%d %d %d\n", x, y, time);
			mtx[x][y] = mtx[y][x] = time;
		}
		for(int i=0; i<s; i++) {
			int x;
			scanf("%d", &x);
			startv.push_back(x);
		}
		for(int i=0; i<d; i++) {
			int x;
			scanf("%d", &x);
			endv.push_back(x);
		}
		//printf("%d\n%d\n", n, startv[0]);
		//dsp();
		for(int i=0; i<startv.size(); i++) {
			djk(startv[i]);
		}
		int min = OO;
		for(int i=0; i<endv.size(); i++) {
			if(min_dist[endv[i]] < min) min = min_dist[endv[i]];
		}
		printf("%d\n", min==OO ? -1 : min);
//	}
	
	return 0;
}

#include <iostream>
#include <limits.h>
#include <string.h>
//#include <Test.h>
#define N 1024

using namespace std;

int mtx[N][N];

int dijkstra(int* m, int start, int n) {

	bool vis[n];
	int dist[n];
	for(int i=0; i<n; i++) { //初始化
		vis[i] = false;
		dist[i] = 999;
	}

	vis[start] = true;
	for(int i=0; i<n; i++) dist[i] = *(m+start*n+i);

	for(int i=1; i<n; i++) {
		int minId = start;
		int minDist = 999;

		for(int k=0; k<n; k++) { //调dist[]里最小的
			if(!vis[k] && dist[k] < minDist) {
				minDist = dist[k];
				minId = k;
			}
		}

		vis[minId] = true;
		for(int k=0; k<n; k++) { //以minId为中间点调整dist[k]
			if(!vis[k] && *(m+n*minId+k) < 999) {
				if(*(m+n*minId+k) + dist[minId] < dist[k]) {
					dist[k] = *(m+n*minId+k) + dist[minId];
				}
			}
		}
	}

	for(int i=0; i<n; i++)
	  cout << dist[i] << '\t';

	return 0;
}

void printMtx(int* m, int n) {
	for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++) {
			cout << *(m+n*i+k) << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void inputMtx() { //输入图
	int n = 0, ec = 0;
	cout << "input the max N: ", cin >> n, cout << endl;
	cout << "input the count edge: ", cin >> ec, cout << endl;
	
	int m[n][n];
	for(int i=0; i<n; i++)
	  for(int k=0; k<n; k++)
		m[i][k] = 99;
	
	for(int i=0; i<ec; i++) {
		int s, e, dist;
		cin >> s >> e >> dist;
		m[--s][--e] = dist;
	}
	for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++) {
			cout << m[i][k] << '\t';
		}
		cout << endl;
	}
	cout << endl;

	dijkstra((int*)m, 0, n);
}

int main(void) {

	inputMtx();
	return 0;
}

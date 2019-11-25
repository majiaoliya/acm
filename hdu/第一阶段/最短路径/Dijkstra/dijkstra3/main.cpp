#include <iostream>
#include <string.h>
#define N 1024
#define M 1024
using namespace std;

void dijkstra(int* mtx, int n, int start) {
/**
	bool vis[n];
	int dist[n];
	for(int i=0; i<n; i++) {
		vis[i] = false;
		dist[i] = *(mtx+n*start+i);
	}
	vis[start] = true;

	for(int i=1; i<n; i++) {
		int minId = start;
		int minDist = M;

		for(int k=0; k<n; k++) {
			if(!vis[k] && dist[k] < minDist) {
				minDist = dist[k];
				minId = k;
			}
		}

		vis[minId] = true;
		for(int k=0; k<n; k++) {
			int* t = (mtx+n*minId+k);
			if(!vis[k] && *t < M) {
				if(*t + dist[minId] < dist[k]) {
					dist[k] = *t + dist[minId];
				}
			}
		}

	}

	for(int i=0; i<n; i++) {
		cout << dist[i] << '\t';
	}
	cout << endl;
*/

	bool vis[n];
	int dist[n];
	for(int i=0; i<n; i++) {
		vis[i] = false;
		dist[i] = *(mtx+n*start+i);
	}

	vis[start] = true;
	for(int i=0; i<n; i++) {
		int minDist = M;
		int minId = start;
		for(int k=0; k<n; k++) {
			if(!vis[k] && dist[k] < minDist) {
				minDist = dist[k];
				minId = k;
			}
		}

		vis[minId] = true;
		for(int k=0; k<n; k++) {
			int* t = mtx+n*minId+k;
			if(!vis[k] && *t+dist[minId] < dist[k]) {
				dist[k] = *t+dist[minId];
			}
		}
	}

	cout << endl;
	for(int i=0; i<n; i++) 
	  cout << dist[i] << '\t';
	cout << endl;
}

void inputMtx() { //输入图
	int n = 0, ec = 0;
	cout << "input the max N: ", cin >> n, cout << endl;
	cout << "input the count edge: ", cin >> ec, cout << endl;
	
	int m[n][n];
	for(int i=0; i<n; i++)
	  for(int k=0; k<n; k++)
		m[i][k] = M;
	
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

	dijkstra((int*)m, n, 0);
}

int main(void) {

	inputMtx();
	return 0;
}

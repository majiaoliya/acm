#include <iostream>
#include <string.h>
#define M 1024
using namespace std;

void inputMtx() {
	int n, ec;
	cin >> n >> ec;

	int mtx[n][n];
	for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++) {
			mtx[i][k] = M;
		}
	}

	for(int i=0; i<ec; i++) {
		int s, e, dist;
		cin >> s >> e >> dist;
		--s, --e;
		mtx[s][e] = mtx[e][s] = dist;
	}

	for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++) {
			cout << mtx[i][k] << '\t';
		}
		cout << endl;
	}
	cout << endl;
	void prim(int*, int, int);
	prim((int*)mtx, n, 0);

}

void prim(int* mtx, int n, int start) {
	bool vis[n];
	int parent[n];
	memset(parent, false, n);
	memset(vis, false, n);
	int dist[n];
	vis[start] = true;
	for(int i=0; i<n; i++) dist[i] = *(mtx+n*start+i);

	for(int i=0; i<n; i++) {
		int minDist = M;
		int minId = start;
		for(int k=0; k<n; k++) {
			if(!vis[k] && *(mtx+n*start+k) < M && minDist < dist[k]) {
				minDist = dist[k];
				minId = k;
			}
		}
		vis[minId] = true;

		cout << parent[minId] << "->" << minId << '\t' << dist[minId] << endl;

		for(int k=0; k<n; k++) {
			if(!vis[k] && *(mtx+n*minId+k) < dist[k]) {
				parent[k] = minId;
				dist[k] = *(mtx+n*minId+k);
			}
		}
	}
	
	for(int i=0; i<n; i++) cout << dist[i] << '\t';
	cout << endl;
}

int main(void) {

	inputMtx();

	return 0;
}

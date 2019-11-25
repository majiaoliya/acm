#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 32
using namespace std;

int t, n, m, ok;
int mtx[MAXN][MAXN];

int di[] = {1, -1, 0, 0};
int dk[] = {0, 0, 1, -1};

void check() {
	ok = false;
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=m; k++) {
			if(i==1 || i==n) {
				for(int mm=1; mm<=m; mm++) {
					if(mm == k) continue;
					if(mtx[i][mm] == mtx[i][k]) {
						ok = true;
//						printf("(%d,%d) = (%d,%d)", i, mm, i, k);
						return;
					}
				}
			}
			if(k==1 || k==m) {
				for(int ii=1; ii<=n; ii++) {
					if(ii == i) continue;
					if(mtx[ii][k] == mtx[i][k]) {
						ok = true;
//						printf("(%d,%d) = (%d,%d)", ii, k, i, k);
						return;
					}
				}
			}
			for(int j=0; j<4; j++) {
				int ni = i+di[j], nk = k+dk[j];
				if(ni>=1 && ni<=n && nk>=1 && nk<=m)
					if(mtx[ni][nk] == mtx[i][k]) {
						ok = true;
//						printf("(%d,%d) = (%d,%d)", ni, nk, i, k);
						return ;
					}
			}
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	for(int i=1; i<=t; i++) {
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++)
			for(int k=1; k<=m; k++)
				scanf("%d", &mtx[i][k]);
		check();
		printf("Case #%d: %s\n", i, ok ? "Yes" : "No");
	}
	return 0;
}

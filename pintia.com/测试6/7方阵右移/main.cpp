#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 512
using namespace std;

int n, m;

int mtx[MAXN][MAXN];

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d", &m, &n);
	for(int i=1; i<=n; i++) 
		for(int k=1; k<=n; k++)
			scanf("%d", &mtx[i][k]);
	
	m %= n;
	m = n - m;
	int lef = m + 1;
	for(int i=1; i<=m; i++) { //把前m列挪到屁股后头
		for(int k=1; k<=n; k++) {
			mtx[k][i+n] = mtx[k][i];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int k=lef; k<lef+n; k++) {
			printf("%d ", mtx[i][k]);
		}
		printf("\n");
	}
	return 0;
}


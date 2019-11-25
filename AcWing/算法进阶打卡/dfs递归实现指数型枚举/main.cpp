#include <iostream> 
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;
#include <iostream>
#include <math.h>
#include <vector>
#define MAXN 16
#define ll long long int
using namespace std;

int n, rs[MAXN], arr[MAXN];
bool vis[MAXN];
/**
void dfs(int x) {
	if(x > n) return;
	for(int i=1; i<=n; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		rs[x] = i;
		dfs(x+1);
		vis[i] = false; 
	}
	for(int i=1; i<x; i++) {
		if(i!=1) printf(" ");
		printf("%d", arr[rs[i]]);
	}
	printf("\n");
}
*/
int table[18] = { 0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767 };

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n); ) {
		for(int i=0; i<=table[n]; i++) {
			int c = 0;
			for(int k=i, j=1; k; k>>=1, j++) {
				if(k&1) {
					if(c++) printf(" ");				
					printf("%d", j);
				}
			}
			printf("\n");
		}
	}
	return 0;
}



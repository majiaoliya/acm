#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define MAXN 5005
using namespace std;

int n, m, arr[MAXN], sum[MAXN*MAXN], pn;

int main(void) {
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		pn = 0;
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		for(int i=1; i<=n; i++)
			for(int k=i+1; k<=n; k++)
				sum[++pn] = arr[i] + arr[k];
		sort(sum+1, sum+1+pn);
		for(int i=pn, k=1; i>=1 && k<=m; i--, k++) {
			if(i!=pn) printf(" ");
			printf("%d", sum[i]);
		}
		printf("\n");
	}
	
	return 0;
}

#include <iostream>
#define MAX 10005

using namespace std;

int n, m;
int mtx[MAX][MAX];

int main() {
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		if(!(n+m)) break;
		for(int i=1; i<=n; i++) 
			for(int k=1; k<=m; k++)
				scanf("%d", mtx[i]+k);
		for(int i=1; i<=n; i++) {
			for(int k=1; k<=m; k++)
				printf("%d,", mtx[i][k]);
			printf("\n");		
		}
		printf("\n");
	}
	return 0;
}

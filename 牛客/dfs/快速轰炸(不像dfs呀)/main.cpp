#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 55

using namespace std;

int n, m;
int mtx[MAX][MAX];

int main()
{
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		for(int i=0; i<n; i++) {
			for(int k=0; k<n; k++) {
				scanf("%d", mtx[i]+k);
			}
		}
		int sum = 0;
		for(int i=0; i<=n-m; i++) {
			for(int k=0; k<=n-m; k++) {
				int t_sum = 0;
				for(int j=0; j<m; j++) {
					for(int z=0; z<m; z++) {
						t_sum += mtx[i+j][k+z];
					}
				}
				sum = sum > t_sum ? sum : t_sum;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}


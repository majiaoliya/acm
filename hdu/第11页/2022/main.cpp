#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN 10005
using namespace std;

int my_abs(int x) { return x > 0 ? x : -x; }
int mtx[MAXN][MAXN];

int main(void) {
	freopen("test", "r", stdin);
	int row, col;
	for( ; EOF != scanf("%d %d", &row, &col); ) {
		int tmax = -2147483648, trow = 1, tcol = 1;
		for(int i=1; i<=row; i++) {
			for(int k=1; k<=col; k++) {
				scanf("%d", mtx[i]+k);
				if(my_abs(mtx[i][k]) > tmax) {
					tmax = my_abs(mtx[i][k]);
					trow = i, tcol = k;
				}
			}
		}
		printf("%d %d %d\n", trow, tcol, mtx[trow][tcol]);
	}
	
	return 0;
}

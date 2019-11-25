#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	int n, m;
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		int tsum = 0, x, count = 0, c = 0;
		for(int i=1; i<=n; i++) {
			x = i*2;
			tsum += x;
			count ++;
			if(count == m) {
				if(c++) printf(" ");
				printf("%d", tsum/count);
				count = 0;
				tsum = 0;
			}
		}
		if(count) {
			if(c++) printf(" ");
			printf("%d", tsum/count);
		}
		printf("\n");
	}
	return 0;
}

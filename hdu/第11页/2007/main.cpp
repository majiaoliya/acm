#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#define float double
using namespace std;

int table[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
	freopen("test", "r", stdin);
	int n, m;
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		if(n > m) swap(n, m);
		int pfh = 0, lfh = 0;
		for(int i=n; i<=m; i++) {
			if(i%2) {
				lfh += pow(i, 3);
			} else {
				pfh += pow(i, 2);
			}
		}
		printf("%d %d\n", pfh, lfh);
	}
	
	return 0;
}

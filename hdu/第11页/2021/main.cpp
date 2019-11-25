#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN 105
using namespace std;

int table[] = {0, 100, 50, 10, 5, 2, 1};
int rs[MAXN], moneys[8];

int main(void) {
	freopen("test", "r", stdin);
	for(int n; (EOF != scanf("%d", &n)) && n; ) {
		int sum = 0;
		for(int i=1; i<=n; i++) {
			int x, tcount=0;
			scanf("%d", &x);
			for(int k=1; k<=6 && x; k++) {
				if(x >= table[k]) {
//					printf("%d张%d,", x/table[k], table[k]);
					tcount += x/table[k];
					x %= table[k];
				}
//				printf("\n");
			}
			sum += tcount;
		}
		printf("%d\n", sum);
	}
	
	
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
using namespace std;

int n, mtx[35][35];

int main(void) {
	freopen("test", "r", stdin);
	mtx[1][1] = 1;
	for(int i=2; i<=31; i++) {
		for(int k=1; k<=i; k++)
			mtx[i][k] = mtx[i-1][k-1] + mtx[i-1][k];
	}
	for( ; cin>>n; ) {
		for(int i=1; i<=n; i++) {
			for(int k=1; k<=i; k++) {
				if(k!=1) printf(" ");
				printf("%d", mtx[i][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}

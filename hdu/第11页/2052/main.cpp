#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n, m;

int main(void) {
	freopen("test", "r", stdin);
	while(cin>>n>>m) {
		printf("+");
		for(int i=0; i<n; i++)
			printf("-");
		printf("+\n");
		for(int i=0; i<m; i++) {
			printf("|");
			for(int i=0; i<n; i++)
				printf(" ");
			printf("|\n");
		}
		printf("+");
		for(int i=0; i<n; i++)
			printf("-");
		printf("+\n\n");
	}
	return 0;
}

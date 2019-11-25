#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n;

int main(void) {
	freopen("test", "r", stdin);
	int x, y;
	for( ; EOF != scanf("%d %d", &x, &y); ) {
		if(y == 1 && x!=0) { printf("No\n"); continue; }
		if(y == 0) { printf("No\n"); continue; }
		int sub = (x-(y-1));
		if(sub % 2 == 0 && sub>=0) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}

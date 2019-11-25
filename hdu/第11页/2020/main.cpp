#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN 100005
using namespace std;

int my_abs(int x) { return x > 0 ? x : -x; }
int cmp(int x, int y) { return my_abs(x) > my_abs(y); }
int arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	
	for(int n; (EOF != scanf("%d", &n)) && n;) {
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		sort(arr+1, arr+1+n, cmp);
		for(int i=1, c=0; i<=n; i++) {
			if(c++) printf(" ");
			printf("%d", arr[i]);
		}
		printf("\n");
	}
	
	return 0;
}

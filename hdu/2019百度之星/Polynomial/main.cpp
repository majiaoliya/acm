#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define min(x,y) ( x > y ? y : x )
#define ll long long int
#define MAXN 10005
using namespace std;

int n, t, x[MAXN], y[MAXN], rs[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(x, false, sizeof(x));
		memset(y, false, sizeof(y));
		memset(rs, false, sizeof(rs));
		for(int i=0; i<n; i++)
			scanf("%d", x+i);
		for(int i=0; i<n; i++)
			scanf("%d", y+i);
		int flag = 1, a, b;
		for(int i=n-1; i>=0; i--) {
			if(x[i] != 0 && y[i] == 0) { // output 1/0
				flag = 1;
				break;
			} else if(x[i] == 0 && y[i] != 0) {
				flag = 2;
				break;
			} else if(x[i] != 0 && y[i] != 0) {
				a = x[i], b = y[i];
				flag = 3;
				break;
			}
		}
		if(flag == 1) printf("1/0\n");
		else if(flag == 2) printf("0/1\n");
		else {
			int gcdab = __gcd(a, b);
			printf("%d/%d\n", a/gcdab, b/gcdab);
		}
	}
	return 0;
}

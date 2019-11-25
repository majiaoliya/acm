#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN 56
using namespace std;

int cows[MAXN] = {0, 1, 2, 3, 4};
int count = 1, n;

int main(void) {
	freopen("test", "r", stdin);
	for(int i=5; i<=55; i++)
		cows[i] = cows[i-3] + cows[i-1];
	for( ; EOF != scanf("%d", &n) && n; ) 
		printf("%d\n", cows[n]);
	return 0;
}

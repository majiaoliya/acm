#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define MAXN 100005
#define random(x) (rand()%x)
using namespace std;

int main(void) {
	freopen("test", "w", stdout);
	srand(time(0));
	int T = 10;
	printf("%d\n", T);
	while(T--) {
		int n = random((int)1e5), m = 10;
		printf("%d %d\n", n, m);
		for(int i=1; i<=n; i++)
			printf("%c", random(26)+'A');
		printf("\n");
		while(m--) {
			int L = random(n)+1, R = random(n)+1;
			printf("%d %d\n", min(L, R), max(L, R)); 
		}
	}
	return 0;
}

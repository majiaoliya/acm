#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN 10005
using namespace std;

int my_abs(int x) { return x > 0 ? x : -x; }
int mtx[MAXN][MAXN];

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		int h, m, s, hh, mm, ss;
		scanf("%d %d %d %d %d %d", &h, &m, &s, &hh, &mm, &ss);
		int ns = (ss+s);
		if(ns >= 60) mm+=1, ns-=60;
		int nm = (mm+m);
		if(nm >= 60) hh+=1, nm-=60;
		printf("%d %d %d\n", (hh+h), nm, ns);
	}
	
	return 0;
}

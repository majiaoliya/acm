#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#define MAXN 600000
using namespace std;

int n;

int func(int x) {
	int sum = 0;
	for(int i=1; i<=(x>>1); i++) {
		if(x%i == 0) 
			sum += i;
	}
	return sum;
}

int main(void) {
	freopen("test", "r", stdin);
	int x, y, t;
	for(cin>>t; t--; ) {
		cin >> x >> y;
		if(func(x)==y && func(y)==x) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}

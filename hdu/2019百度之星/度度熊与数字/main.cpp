#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
#define min(x,y) ( x > y ? y : x )
#define ll long long int
#define MAXN 10005
using namespace std;

int t, v;

int sumit(int a) {
	int rs = 0;
	while(a) {
		rs += a%10;
		a /= 10;
	}
	return rs;
}

bool check(int a, int b, int mod) {
	return a%mod == 0 && b%mod == 0;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &v);
		set<int> seta;
		int sum = sumit(v);
		for(int i=1; i<=sum; i++) {
			if(check(sum, v, i)) seta.insert(i);
		}
		set<int>::iterator it = seta.begin();
		printf("%d\n", seta.size());
		while(it != seta.end()) {
			if(it != seta.begin()) printf(" ");
			printf("%d", *it);
			it ++;
		}
		printf("\n");
	}
	return 0;
}

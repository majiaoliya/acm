#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#define _int long long int
#define M 1000
using namespace std;

_int fp(_int a, _int b) {
	_int ret = 1, tb = b;
	while(b>0) {
		if(b&1) ret = ret*a%M;
		a = a*a % M;
		b >>= 1;
	}
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	_int n, m;
	for( ; (EOF!=scanf("%lld %lld", &n, &m)) && (n+m); ) {
		_int rs = fp(n, m);
		stack<_int> stk;
		_int t=3;
		while(rs && t--) {
			stk.push(rs%10);
			rs /= 10;
		}
		for(; !stk.empty(); ) {
			printf("%d", stk.top());
			stk.pop();
		}
		printf("\n");
	}
	
	return 0;
}

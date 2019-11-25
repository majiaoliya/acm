#include <iostream>
#define ull unsigned long long int
using namespace std;

ull fp(ull a, ull b, ull p) {
	ull rs = 1 % p;
	while(b) {
		if(b&1) rs = (rs+a) % p;
		a = a*2 % p;
		b >>= 1;
	}
	return rs;
}

int main(void) {
	freopen("test", "r", stdin);
	for(ull a, b, p; cin>>a>>b>>p; ) {
		printf("%lld\n", fp(a, b, p));
	}
	return 0;
}

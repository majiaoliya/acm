#include <iostream>
using namespace std;
/**
 * c++一秒大概能算 1e7~~1e8 次
 * 求a^b mod p
 */ 
 
int fp(int a, int b, int p) { //求a^b mod p
	int rs = 1%p;
	while(b) {
		if(b&1) rs = rs*1ll*a % p;
		a = a*1ll * a % p;
		b >>= 1;
	}
	return rs;
}

int main(void) {
	freopen("test", "r", stdin);
	for(int a, b, p; cin>>a>>b>>p; ) {
		printf("%d\n", fp(a, b, p));
	}
	return 0;
}

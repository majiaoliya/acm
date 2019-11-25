#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define ll long long int
using namespace std;

ll gcd(ll a, ll b) {
	return b==0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a/g*b;
}

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		ll a,b;
		scanf("%lld %lld", &a, &b);
		if(a == b) { printf("%lld %lld %lld %lld\n", a, a, a, a); continue; }
//		printf("%lld %lld %lld 1\n", b*(b-1), lcm(a,a), gcd(b,b));
		printf("%lld %lld %lld 1\n", b*(b-1), a, b);
	}
//	int lef = 3, rig = 3;
//	for(int i=lef; i<=rig; i++)
//		for(int k=lef; k<=rig; k++)
//			printf("lcm(%d,%d) = %lld\n", i, k, lcm(i,k));
//	printf("\n最大公约束\n");
//	for(int i=lef; i<=rig; i++)
//		for(int k=lef; k<=rig; k++)
//			printf("gcd(%d,%d) = %lld\n", i, k, gcd(i,k));
		
	return 0;
}



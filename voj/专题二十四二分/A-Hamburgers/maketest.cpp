#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <time.h>
#include <stdlib.h>
#define random(x) (rand()%x)
#define ll long long int 
using namespace std;

int main() {
	freopen("test", "w", stdout);
	int t = 10;
	srand(time(0));
	while(t--) {
		int B = random(10), C = random(10), S = random(10);
		char buf[180];
		int idx = -1;
		while(true) {
			if(!B && !C && !S) break;
			if(B) buf[++idx] = 'B', B--;
			if(C) buf[++idx] = 'C', C--;
			if(S) buf[++idx] = 'S', S--;
		}
		buf[++idx] = 0;
		printf("%s\n", buf);
		ll a = random(50), b = random(50), c = random(50);
		printf("%lld %lld %lld\n", a, b, c);
		ll x = random(50), y = random(50), z = random(50);
		printf("%lld %lld %lld\n", x, y, z);
		ll money = random(50);
		printf("%lld\n\n", money);
	}
	// 4b  2s  7c
//	   33*4*35+2*10*48+48*7*17
//	33*35+10*48+48*17+7
	
    return 0;
}

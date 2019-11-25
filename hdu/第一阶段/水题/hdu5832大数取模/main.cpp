#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

//char x[1024*1024];
char x[10000000+10];

int main(void) {
	freopen("test", "r", stdin);
	int tmod = 73*137, count=1;
	for( ; EOF != scanf("%s", x); ) {
//		printf("Case #%lld: %s\n", count++, n%tmod==0 ? "YES":"NO");
		int len = strlen(x);
		int rs = 0;
		for(int i=0; x[i]; i++) {
			rs = rs*10 + (x[i] - '0');
			rs %= tmod;
		}
		printf("Case #%d: %s\n", count++, rs==0 ? "YES":"NO");		
	}
	
	return 0;
}

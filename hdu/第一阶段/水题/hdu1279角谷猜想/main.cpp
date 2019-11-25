#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 5005
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		int n, tag = 0;
		scanf("%d", &n);
		while(n != 1) {
			if(n&1) { 
				tag ++;
				if(tag != 1) printf(" ");
				printf("%d", n);
				n*=3; n++;
			}
			else n >>= 1;
		}
		printf("%s\n", tag ? "" : "No number can be output !");
	}
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

//当某人面对3的倍数时，他必败，因为他总是取不完，并且另一人有可能取完，也有可能再构造一个3的倍数给他。

int main(void) {
	freopen("test", "r", stdin);
	int n;
	for( ; ~scanf("%d", &n); ) {
		if(n == 1) {
			printf("qiandaoshibai\n");
		} else if(n == 2) {
			printf("qiandaochenggong\n");
		} else {
			printf("%s\n", (n-2)&1 ? "qiandaoshibai" : "qiandaochenggong");
		}
	}	
	return 0;
}

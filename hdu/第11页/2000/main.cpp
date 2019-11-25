#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	//freopen("test", "r", stdin);
	char a, b, c;
	char buf[3];
	for( ; EOF != scanf("%s", buf); ) {
		sort(buf, buf+3);
		for(int i=0, c=0; i<3; i++) {
			if(c++) printf(" ");
			printf("%c", buf[i]);
		}
		printf("\n");
	}

	return 0;
}

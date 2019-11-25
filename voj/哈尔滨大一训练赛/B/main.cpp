#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;



int main(void) {
	freopen("test", "r", stdin);
	int x, y, z;
	for( ; EOF != scanf("%d %d %d", &x, &y, &z); ) {
		int rs = 3*x + 2*y + 6*z;
		printf("%s\n%d\n", rs>=60 ? "I passed the exam." : "Exam was too hard.",  rs);
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	freopen("test", "r", stdin);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a==b) printf("C\n");
	else if(a==c) printf("B\n");
	else if(b==c) printf("A\n");
	return 0;
}


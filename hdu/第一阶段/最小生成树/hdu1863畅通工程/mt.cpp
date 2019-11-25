#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define random(x) (random()%x)
using namespace std;

int main(void) {
	srand(time(0));
	freopen("test", "w", stdout);
	int n = random(30), m = random(15)+1;
	printf("%d %d\n", n, m);
	
	for(int i=1; i<=n; i++) {
		int a = random(m) + 1, b = random(m) + 1, d = random(30);
		printf("%d %d %d\n", a, b, d);
	}
	printf("0 2");

	return 0;
}

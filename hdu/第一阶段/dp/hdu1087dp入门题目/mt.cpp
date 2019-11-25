#include <bits/stdc++.h>
#define random(x) (rand()%x)
using namespace std;

int main(void) {
	freopen("test", "w", stdout);
	srand(time(0));
	for(int i=1; i<=5; i++) {
		int n = random(20);
		printf("%d", n);
		while(n--) 
			printf(" %d", random(30));
		printf("\n");
	}
	printf("0\n");
	return 0;
}

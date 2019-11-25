#include <iostream>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)
using namespace std;

int main(void) {
	freopen("test", "w", stdout);
	srand((int)time(0));
	int N, M;
	for(int ii=1; ii<=10; ii++) {
		N = random(200000-1), M = random(5000-1);
		printf("%d %d\n", N, M);
		for(int i=0; i<N; i++) {
			if(i) printf(" ");
			printf("%d", random(100));
		}
		printf("\n");
		char cmd[4] = { 'Q', 'U' };
		for(int i=1; i<=M; i++) {
			int a = random(N), b = random(N);
			printf("%c %d %d\n", cmd[random(2)], min(a, b), max(a, b));
		}
	}
		
	return 0;
}















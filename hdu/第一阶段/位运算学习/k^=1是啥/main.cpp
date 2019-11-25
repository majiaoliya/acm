#include <iostream>
using namespace std;

int main(void) {
	
	for(int i=1; i<=20; i++) {
		int temp = i;
		while(temp) {
			printf("%d", temp&1);
			temp >>= 1;
		}
		printf("^1 = ");
		temp = i^1;
		while(temp) {
			printf("%d", temp&1);
			temp >>= 1;
		}
		printf(" = %d\n", i^1);
	}
	return 0;
}

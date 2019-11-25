#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    
    char x = 9;
	for(int i=7; i>=0; i--) {
		printf("%d", x>>i&1);
	}
	            //下标      76543210
	x = x|1<<2; // 9      = 00001001
	            // 9|1<<2 = 00001101
	printf("\n");
	for(int i=7; i>=0; i--) {
		printf("%d", x>>i&1);
	}
	
	return 0;
}

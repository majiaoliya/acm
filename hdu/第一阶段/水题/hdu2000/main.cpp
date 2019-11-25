#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

	char arr[4];
	for( ; scanf("%s", arr)!=EOF; ) {
		sort(arr, arr+3);
		for(int i=0; i<3; i++) {
			if(i) printf(" ");
			printf("%c", arr[i]);
		}
		printf("\n");
	}
	return 0;
}

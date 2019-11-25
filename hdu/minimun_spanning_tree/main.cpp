#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int main() {
	int n = 3;
	for(int i=1; i<=n; i++) {
		for(int k=i+1; k<=n; k++) {
			printf("%d & %d = %d\n", i, k, i&k);
		}
	}
	return 0;
}


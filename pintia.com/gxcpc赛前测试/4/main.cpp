#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	freopen("test", "r", stdin);
	string num;
	for( ; cin>>num; ) {
		int sum = 0;
		for(int i=0; i<num.length(); i++) {
			sum += num[i] - '0';
		}
		printf("%d %d\n", num.length(), sum);
	}
	return 0;
}


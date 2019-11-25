#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define ll long long int 
using namespace std;
int t, arr[6];

int main(void) {
	freopen("test", "r", stdin);
	for(ll i=1000000000; i<1145141919810; i++) {
		ll sum = 0, ti = i;
		while(ti) {
			sum += ti%10;
			ti /= 10;
		}
		if(sum/2 == sum)
			printf("[%lld %lld]\n", i, sum);
	}
	return 0;
}

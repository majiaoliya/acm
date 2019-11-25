// https://nanti.jisuanke.com/t/17309
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX (1024<<4)
using namespace std;
/**
struct Entry {
	int start, end, people;
	Entry() : start(0), end(0), people(0) { }
};

Entry arr[MAX];

int cmp(Entry& x, Entry& y) { return x.end < y.end; }
*/

long long arr[MAX];

int main(void) {
	freopen("test", "r", stdin);
	int n;
	for( ; EOF != scanf("%d", &n); ) {
		if(!n) {
			printf("*\n");
			break;
		}
		long long max_count = 0;
		memset(arr, false, sizeof(arr));
		for(int i=0; i<n; i++) {
			long long start, end, count;
			scanf("%lld %lld %lld", &start, &end, &count);
			if(start > end) swap(start, end);
			for(int k=start; k<end; k++) {
				arr[k] += count;
				if(arr[k] > max_count) max_count = arr[k];
			} 
		}
		printf("%lld\n", max_count);
	}
	
	return 0;
}

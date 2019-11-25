#include <iostream>
#include <algorithm>
#include <string.h>
#define M 600
using namespace std;

int arr[M];
bool cmp(int x, int y) { return x > y; }

int main(void) {

	int l, n;
	for( ; scanf("%d", &l)!=EOF && scanf("%d", &n)!=EOF; ) {
		for(int i=0; i<n; i++) { scanf("%d", arr+i); }
		std::sort(arr, arr+n, cmp);
		int count = 0;
		for(int i=0; i<n && l>0; i++) {
			l -= arr[i];
			count ++;
		}
		if(l <= 0)
			cout << count << endl;
		else 
			cout << "impossible" << endl;
	}
	
	return 0;
}

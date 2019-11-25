#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 100
using namespace std;

int n, sum, avg, rs, arr[MAXN];

int abs(int x) { return x > 0 ? x : -x; }

int main(void) {
//	freopen("test", "r", stdin);
	int ok = false;
	while(cin>>n && n) {
		if(ok++) printf("\n");
		sum = 0, rs = 0;
		for(int i=0; i<n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		int avg = sum / n;
		for(int i=0; i<n; i++)
			if(arr[i] > avg)
				rs += abs(avg-arr[i]);
		printf("%d\n", rs);
	}
	return 0;
}

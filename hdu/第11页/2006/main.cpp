#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#define float double
using namespace std;

int table[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
	freopen("test", "r", stdin);
	for(int n; EOF != scanf("%d", &n); ) {
		int sum = 0, tag = true;
		for(int i=1; i<=n; i++) {
			int x;
			scanf("%d", &x);
			if(x%2) {
				if(tag) {
					sum = x;
					tag = false;
				} else {
					sum *= x;
				}
			}
		}
		printf("%d\n", sum);
	}
	
	return 0;
}

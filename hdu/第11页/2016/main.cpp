#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN 105
using namespace std;

int arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	int n;
	for( ; EOF != scanf("%d", &n) && n; ) {
		int minx = 0x7fffffff, min_id = 0;
		for(int i=0; i<n; i++) {
			scanf("%d", arr+i);
			if(!i) 
				minx = arr[i], min_id = i;
			else {
				if(minx > arr[i]) {
					minx = arr[i];
					min_id = i;
				}
			}
		}
		swap(arr[0], arr[min_id]);
		for(int i=0, c=0; i<n; i++) {
			if(c++) printf(" ");
			printf("%d", arr[i]);
		}
		printf("\n");
	}
	return 0;
}

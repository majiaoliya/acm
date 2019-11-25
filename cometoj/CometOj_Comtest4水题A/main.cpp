#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define ll long long int 
using namespace std;
int t, arr[6];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	for( ; t--; ) {
		memset(arr, false, sizeof(arr));
		for(int i=1, x; i<=5; i++) {
			scanf("%d", &x);
			arr[x] ++;
		}
		int i, tmin, id;
		for(i=2, tmin=arr[1], id=1; i<=5; i++) {
			if(tmin < arr[i]) {
				id = i;
				tmin = arr[i];
			}	
		}
		printf("%d\n", id);
	}
	
	return 0;
}

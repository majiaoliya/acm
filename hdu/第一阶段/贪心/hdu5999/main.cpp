#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n;
int arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	int t;
	int temp = 1;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", arr+i);
		sort(arr, arr+n);
		int count = 0, sum = 0;
		for(int i=n-1; i>=0; i--) {
			count ++;
			if(count == 3) {
				count = 0;
				continue ;
			}
			sum += arr[i];
		}
		printf("Case #%d: %d\n", temp++, sum);
	}

	return 0;
}

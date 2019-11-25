#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int len, n, m, arr[MAXN];
int high = 0, low = -1, mid;

bool slove() {
	int res = 1, sum = 0;
	for(int i=0; i<=n; i++) {
		sum += arr[i];
		if(sum >= mid) {
			++res;
			if(sum == mid) sum = 0;
			else sum = arr[i];
			if(i == n-1) -- res;
		}
	}
	if(res > m) return false;
	else return true;
}

int main(void) {
	freopen("test", "r", stdin);
	
	while(EOF != scanf("%d %d", &n, &m)) {
		high = 0, low = -1;
		for(int i=0; i<n; i++) {
			 scanf("%d", arr+i);
			 if(arr[i] > low) low = arr[i];
			 high += arr[i];
		}
		while(low < high) {
			mid = (low + high) >> 1;
			if(slove()) high = mid - 1;
			else low = mid + 1;
		}
		cout << low << endl;
	}
	
	return 0;
}

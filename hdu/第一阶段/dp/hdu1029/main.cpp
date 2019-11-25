
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 1000100
using namespace std;
int n, arr[MAXN];

int main()
{
	freopen("test", "r", stdin);
	while(EOF != scanf("%d", &n)) {
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		sort(arr+1, arr+1+n);
		int cnt = 1, temp = arr[1];
		for(int i=2; i<=n; i++) {
			if(temp == arr[i]) {
				cnt ++;
				if(cnt >= (n+1)/2) break;
			} else {
				temp = arr[i];
				cnt = 1;
			}
		}
		printf("%d\n", temp);
	}
	return 0;
}




#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int MAXN = 1e6+10; 
int arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
		
	int n;
	for( ; EOF != scanf("%d", &n); ) {
		int x = 0, tmax = 0, cnt = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &x);
			tmax = max(x, tmax);
			arr[x] ++; //类似于桶的存储方式
		}
		for(int i=1; i<=tmax; i++) {
			if(arr[i]) {
				if(arr[i]>=2) {
					cnt += arr[i] / 2;
					arr[i] %= 2;
				}
				if(i<=tmax-2) {
					if(arr[i] && arr[i+1]%2 && arr[i+2]) {
						cnt ++;
						arr[i]--, arr[i+1]--, arr[i+2]--;
					}
				}
				arr[i] = 0;
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}

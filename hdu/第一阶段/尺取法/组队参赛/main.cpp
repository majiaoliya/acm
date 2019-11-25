// 尺取法
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

// 求一段连续区间 r[L, R] 且每个数字差值<=5 

const int MAXN = 1e6+7;
int n, m, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i=0; i<n; i++) 
			scanf("%d", arr+i);
		sort(arr, arr+n);
		int i = 0, j = 0, rs = 1;
		for( ; ; ) {
			while(arr[j]-arr[i]<=5 && j<n)
				j++;
			rs = max(rs, j-i);
			i ++;
			if(i >= n) break;
		}
		printf("%d\n", rs);
	}
	return 0;
}



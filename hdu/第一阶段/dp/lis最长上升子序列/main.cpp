
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 100005
using namespace std;

int n, arr[MAXN], dp[MAXN], len, lis[MAXN];

int binsearch(int key) { // 返回第一个大于等于key的位置
	int lef = 1, rig = len, mid, ret = 1;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(key <= lis[mid]) ret = mid, rig = mid - 1;
		else lef = mid + 1;
	}
	return ret;
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", arr+i);
	int ans = 0;
	/** O(n^2)
	for(int i=1; i<=n; i++) {
		dp[i] = 1;
		for(int k=1; k<i; k++) {
			//改成arr[i] >= arr[k]就是最长不下降子序列
			if(arr[i] > arr[k]) dp[i] = max(dp[i], dp[k]+1);
			ans = max(ans, dp[i]); //ans就是最长递增子序列的长度
		}
	}
	*/
	
	//下面是O(nlogn)的做法
	lis[1] = arr[1];
	len = 1;
	ans = 1;
	for(int i=2; i<=n; i++) {
		if(arr[i] > lis[len]) 
			lis[++len] = arr[i];
		else {
			int pos = binsearch(arr[i]); //返回 >= 所查找对象arr[i]的第一个位置
//			printf("bins(%d) pos:%d\n", arr[i], pos);
			lis[pos] = arr[i];
		}
	}
	ans = len;
	printf("%d\n", n-ans);
	return 0;
}




#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int len, n, m, arr[MAXN];
/**
    二分的思想就是：假设答案为mid。那么：
    mid中2的倍数就是：mid/2
    mid中3的倍数就是：mid/3
    mid中6的倍数就是：mid/6

    那假设真正的答案是ans。对于大于或者等于ans的mid来说，肯定有：mid/2+mid/3-mid/6>=n+m
    同理，小于ans的肯定有mid/2+mid/3-mid/6<n+m
    所以，我们假设l=1， r=无穷大，只要通过这两个条件不断对区间进行二分，必然会得到正确的答案。
*/

bool check(int k) {
	int num2 = k/2, num3 = k/3, num6 = k/6;
	return num2>=n && num3>=m && num2+num3-num6>=n+m ;
}

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		int lef = 1, rig = 1e7+10, ans = 0;
		while(lef <= rig) {
			int mid = (lef + rig) >> 1;
			if(check(mid)) ans = mid, rig = mid - 1;
			else lef = mid + 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}

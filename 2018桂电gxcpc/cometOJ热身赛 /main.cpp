//https://www.cometoj.com/contest/6/problem/C?problem_id=73

//Novus Aither是一个潜藏着多个势力的城市。每个势力都有一个唯一的领导人，每个领导人有一个属性值。如果两个势力的领导人的属性值分别为a,ba,ba,b，且∣a−b∣≤m|a-b| \le m∣a−b∣≤m，说明这两个领导人的思想有一定的相似之处，这两个势力可以合并，新的领导人可以指定为原来的两个领导人中的任意一个。新产生的势力可以依照相同的规则，继续与其他势力合并。问在所有可能的合并情况中，最少会剩下几个势力。


#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAXN 1000007

using namespace std;

int n, m, arr[MAXN];
int pre[MAXN];
int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry)
		pre[ry] = rx;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		pre[i] = -1;
	for(int i=1; i<=n; i++) 
		scanf("%d", arr+i);
	sort(arr+1, arr+1+n);
	int lst = arr[1], lst_id = 1;
	for(int i=2; i<=n; i++) {
		if(abs(lst-arr[i]) <= m) union_xy(lst_id, i);
		lst = arr[i];
		lst_id = i;
	}
	int cnt = 0;
	for(int i=1; i<=n; i++)
		if(pre[i] == -1) cnt ++;
	printf("%d\n", cnt);
	return 0;
}

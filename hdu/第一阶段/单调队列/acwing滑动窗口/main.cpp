#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN ((int)1e+7)
int n, k, a[MAXN], q[MAXN];

int main(void) {
	freopen("test", "r", stdin);
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", a+i);
	int lef = 0, rig = -1; //队列存储的是下标
	for(int i=0; i<n; i++) {
		if(lef<=rig && q[lef] < i-k+1) lef ++; //先判断是否吧队头出队
		while(lef<=rig && a[q[rig]]>=a[i]) rig --; //把队尾所有比a[i]大的移除
		q[++rig] = i; //a[i]入队
		if(i >= k-1) printf("%d ", a[q[lef]]); //打印对头
	}
	puts("");
	lef = 0, rig = -1;
	for(int i=0; i<n; i++) {
		if(lef<=rig && q[lef] < i-k+1) lef ++; 
		while(lef<=rig && a[q[rig]]<=a[i]) rig --;
		q[++rig] = i;
		if(i >= k-1) printf("%d ", a[q[lef]]);
	}
	puts("");
	return 0;
}

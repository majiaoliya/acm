#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long int

const int MAXN = 1e6+7;

int n, arr[MAXN], t, x, cmd, size;

void push(int x) {
	arr[++size] = x;
	int cur = size;
	while((cur>>1) > 0) {
		if(arr[cur>>1] <= arr[cur]) break;
		swap(arr[cur>>1], arr[cur]);
		cur >>= 1;
	}
}

void pop() {
	int cur = 1, lef, rig, min_id;
	arr[1] = arr[size--];
	while(cur <= size) {
		min_id = cur, lef = cur*2, rig = cur*2+1;
//		printf("%d %d %d\n", cur, lef, rig);
		if(lef<=size && arr[lef]<arr[min_id]) min_id = lef;
		if(rig<=size && arr[rig]<arr[min_id]) min_id = rig;
		if(min_id == cur) break;
		swap(arr[min_id], arr[cur]);
		cur = min_id;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	//while(~scanf("%d", &x)) push(x);
	//while(size) {
	//	printf("%d, ", arr[1]);
	//	pop();
	//}
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &cmd);
		if(cmd == 1) {
			scanf("%d", &x);
			push(x);
		} else if(cmd == 2) {
			printf("%d\n", arr[1]);
		} else {
			pop();
		}
	}
	return 0;
}




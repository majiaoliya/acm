#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXN 50005
using namespace std;

// lef = 2i, rig = 2i+1
int sum[MAXN*4], arr[MAXN], n;

//void push_up(int xnode) {
//	sum[xnode] = sum[xnode*2] + sum[xnode*2+1];
//}

//void build(int lef, int rig, int xnode) {
//	if(lef == rig) {
//		sum[xnode] = arr[lef];
//		return ;
//	}
//	int mid = (lef+rig)>>1;
//	build(lef, mid, xnode*2);
//	build(mid+1, rig, xnode*2+1);
//	push_up(xnode);
//}

//int query(int lef, int rig, int xnode, int L, int R) { //查询[L,R]区间
//	if(L<=lef && rig<=R) { //要查询的区间完全落在节点里
//		return sum[xnode];
//	}
//	int mid = (lef+rig) >> 1, rs = 0;
//	if(L<=mid) //[L,R]有一部分和xnode的左半边重合
//		rs += query(lef, mid, xnode*2, L, R);
//	if(R>mid) //[L,R]有一部分和xnode右半边重合
//		rs += query(mid+1, rig, xnode*2+1, L, R);
//	return rs;		
//}

//void point_update(int xnode, int lef, int rig, int idx, int value) { //单点修改
//	if(lef == rig) {
//		sum[xnode] = value;
//		return ;
//	}
//	int mid = (lef+rig) >> 1;
//	if(idx<=mid)
//		point_update(xnode*2, lef, mid, idx, value);
//	else
//		point_update(xnode*2+1, mid+1, rig, idx, value);
//	push_up(xnode); 
//}

void push_up(int xnode) { sum[xnode] = sum[xnode<<1] + sum[(xnode<<1)+1]; }

void build(int lef, int rig, int xnode) {
	if(lef==rig) { sum[xnode] = arr[lef]; return; }
	int mid = (lef+rig)>>1;
	build(lef, mid, xnode<<1);
	build(mid+1, rig, (xnode<<1)+1);
	push_up(xnode);
}

//int query(int xnode, int lef, int rig, int L, int R) {
//	if(L<=lef && rig<=R)
//		return sum[xnode];
//	int mid = (lef+rig)>>1, rs = 0;
//	if(mid>=L) rs += query(xnode*2, lef, mid, L, R);
//	if(mid>R) rs += query(xnode*2+1, mid+1, rig, L, R);
//	return rs;
//}

int query(int xnode, int lef, int rig, int L, int R) {
	if(L<=lef && R>=rig) return sum[xnode];
	else if(R<lef || L>rig) return 0;
	int mid = (lef+rig) >> 1, rs = 0;
	if(mid>=L) rs += query(xnode<<1, lef, mid, L, R);
	if(mid<R) rs += query((xnode<<1)+1, mid+1, rig, L, R);
	return rs;
}

void point_update(int xnode, int lef, int rig, int idx, int value) {
	if(lef == rig) {
		sum[xnode] += value;
		arr[idx] += value;
		return;
	}
	int mid = (lef+rig) >> 1;
	if(idx<=mid) point_update(xnode*2, lef, mid, idx, value);
	else point_update(xnode*2+1, mid+1, rig, idx, value);
	push_up(xnode);
}

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(sum, false, sizeof(sum));
		memset(arr, false, sizeof(arr));
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		build(1, n, 1);
		char cmd[16];
		while(scanf("%s", cmd) && cmd[0]!='E') {
			int idx, value;
			if(cmd[0] == 'Q') {
				int L, R;
				scanf("%d %d", &L, &R);
//				for(int i=1; i<=n; i++)
//					printf("%d ", arr[i]);
//				printf("\n");
//				for(int i=1; i<=(4*n); i++)
//					printf("%d ", sum[i]);
//				printf("\n");
				printf("%d\n", query(1, 1, n, L, R));
			} else if(cmd[0] == 'A') {
				scanf("%d %d", &idx, &value);
				point_update(1, 1, n, idx, value);
			} else if(cmd[0] == 'S') {
				scanf("%d %d", &idx, &value);
				point_update(1, 1, n, idx, -value);
			}
		}
	}
	return 0;
}

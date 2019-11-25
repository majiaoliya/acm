//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <string.h>
//#define MAXN 200005
//using namespace std;

//int t, n, m;
//int tmax[MAXN*4], arr[MAXN];

//void push_up(int xnode) {
//	tmax[xnode] = max(tmax[xnode<<1], tmax[xnode<<1|1]);
//}

//void build(int xnode, int lef, int rig) {
//	if(lef == rig) {
////		scanf("%d", &tmax[xnode]);
//		tmax[xnode] = arr[lef];
//		return ;
//	}
//	int mid = (lef+rig) >> 1;
//	build(xnode<<1, lef, mid);
//	build(xnode<<1|1, mid+1, rig);
//	push_up(xnode);
//}

//int query(int xnode, int lef, int rig, int L, int R) {
//	if(L<=lef && rig<=R) 
//		return tmax[xnode];
//	int mid = (lef+rig)>>1;
////	return max(query(xnode<<1, lef, mid, L, R), query(xnode<<1|1, mid+1, rig, L, R));
//	int ret = 0;
//	if(L<=mid) ret = max(ret, query(xnode, lef, mid, L, R));
//	if(R>mid) ret = max(ret, query(xnode, mid+1, rig, L, R));
//	return ret;
//}

//void update(int xnode, int lef, int rig, int idx, int val) {
//	if(lef == rig) {
//		tmax[xnode] = arr[idx] = val;
//		return;
//	}
//	int mid = (lef+rig) >> 1;
//	if(idx <= mid)
//		update(xnode<<1, lef, mid, idx, val);
//	else 
//		update(xnode<<1|1, mid+1, rig, idx, val);
//	push_up(xnode);
//}

//int main(void) {
//	freopen("test", "r", stdin);
//	while(EOF!=scanf("%d %d", &n, &m)) {
//		for(int i=1; i<=n; i++)
//			scanf("%d", arr+i);
//		build(1, 1, n);
//		char cmd[4];
//		while(m--) {
//			scanf("%s", cmd);
//			if(cmd[0] == 'Q') { //query
//				int L, R;
//				scanf("%d %d", &L, &R);
//				printf("%d\n", query(1, 1, n, L, R));
//			} else if(cmd[0] == 'U') { //update
//				int idx, val;
//				scanf("%d %d", &idx, &val);
//				update(1, 1, n, idx, val);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}






#include <iostream>
const int maxn = 200005;
int arr[maxn], tmax[maxn*4], n, m;

int max(int x, int y) { return x > y ? x : y; }

void push_up(int x) {
	tmax[x] = max(tmax[x<<1], tmax[x<<1|1]);
}

void build(int x, int lef, int rig) {
	if(lef == rig) {
		tmax[x] = arr[lef];
		return;
	}
	int mid = (lef+rig) >> 1;
	build(x<<1, lef, mid);
	build(x<<1|1, mid+1, rig);
	push_up(x);
}

int query(int x, int lef, int rig, int L, int R) {
	if(L<=lef && rig<=R) return tmax[x];
	int mid = (lef+rig) >> 1, ret = 0;
	if(L<=mid) ret = max(ret, query(x*2, lef, mid, L, R));
	if(R>mid) ret = max(ret, query(x*2+1, mid+1, rig, L, R));
	return ret;
}

void update(int x, int lef, int rig, int idx, int val) {
	if(lef == rig) {
		tmax[x] = arr[idx] = val;
		return ;
	}
	int mid = (lef+rig) >> 1;
	if(idx<=mid) update(x<<1, lef, mid, idx, val);
	if(idx>mid) update(x<<1|1, mid+1, rig, idx, val);
	push_up(x);
}
 
int main(void) {
//	freopen("test", "r", stdin);
//	freopen("main_out", "w", stdout);
	while(EOF != scanf("%d %d", &n, &m)) {
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		build(1, 1, n);
		int a, b;
		char ch;
		while(m--) {
			scanf(" %c%d%d", &ch, &a, &b);
			if(ch == 'Q') printf("%d\n", query(1, 1, n, a, b));
			else update(1, 1, n, a, b);
		}
	}
	return 0;
}















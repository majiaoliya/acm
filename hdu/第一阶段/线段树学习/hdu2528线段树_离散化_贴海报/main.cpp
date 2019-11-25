//#include <iostream>
//#include <algorithm>
//#include <string.h>
//#define MAXN 100005
//#define ll long long 
//using namespace std;
//
//struct Node {
//	int L, R;
//} q[MAXN<<4];
//
//int t, n, arr[MAXN<<4], lsh[MAXN<<4], lazy[MAXN<<4], cnt;
//
//void push_down(int x) {
//	if(lazy[x]) {
//		lazy[x<<1] = lazy[x];
//		lazy[x<<1|1] = lazy[x];
//		lazy[x] = 0; 
//	}
//}
//
//int binsearch(int lef, int rig, int val) {
//	int mid = -1;
//	while(lef<=rig) {
//		mid = (lef+rig) >> 1;
////		printf("mid:%d  ", mid);
//		if(lsh[mid] < val) 
//			lef = mid+1;
//		else if(lsh[mid] > val)
//			rig = mid-1;
//		else if(lsh[mid] == val)
//			break;
//	}
//	printf("\n");
//	return mid;
//}
//
//void update(int x, int lef, int rig, int L, int R, int val) {
//	if(L<=lef && rig<=R) {
//		lazy[x] = val;
//		return ;
//	}
//	push_down(x);
//	int mid = (lef+rig) >> 1;
//	if(L<=mid) update(x<<1, lef, mid, L, R, val);
//	if(mid<R) update(x<<1, mid+1, rig, L, R, val);
//}
//
//void query(int x, int lef, int rig, int L, int R) {
//	if(lef == rig) {
//		arr[lef] = lazy[x];
//		return ;
//	}
//	push_down(x);
//	int mid = (lef+rig) >> 1;
//	if(L<=mid) query(x<<1, lef, mid, L, R);
//	if(mid<rig) query(x<<1|1, mid+1, rig, L, R);
//}
//
//int main(void) {
//	freopen("test", "r", stdin);
//	scanf("%d", &t);
////	for(int i=1; i<=9; i++)	
////		printf("%d: %d \n", i, binsearch(1, 9, i));
//	while(t--) {
//		cnt = 0;
//		memset(arr, false, sizeof(arr));
//		scanf("%d", &n);
//		int tot = 0;
//		for(int i=1; i<=n; i++) {
//			scanf("%d %d", &q[i].L, &q[i].R);
//			lsh[++tot] = q[i].L, lsh[++tot] = q[i].R;
//		}
//		sort(lsh+1, lsh+1+tot);
//		int mm = unique(lsh+1, lsh+1+tot) - (lsh+1);
//		sort(lsh+1, lsh+1+mm);
//		for(int i=1; i<=n; i++) {
//			int L = binsearch(1, 1+mm, q[i].L);
//			int R = binsearch(1, 1+mm, q[i].R);
////			printf("try update(%d, %d) %d\n", L, R, mm);
//			update(1, 1, mm, L, R, ++cnt);
//		}
//		query(1, 1, mm, 1, mm);
//		int rs = 0;
//		bool vis[cnt+3] = { 0 };
//		for(int i=1; i<=mm; i++) {
//			printf("[%d]", arr[i]);
//			if(vis[arr[i]]) continue;
//			vis[arr[i]] = true;
//			rs ++;
//		}
//		printf("%d\n", rs);
//	}
//
//	//	//for(int i=1; i<=mm; i++) {
//	//	//	printf("%d  ", lsh[i]);
//	//	//}
//	//}
//	return 0;
//}


#include <iostream>
#include <algorithm>
#define MAXN 1000005
using namespace std;

int t, n, arr[MAXN], tree[MAXN], lazy[MAXN], temp[MAXN];

struct Node {
	int L, R;
} q[MAXN];

int binsearch(int lef, int rig, int val) {
	int mid = -1;
	while(lef <= rig) {
		mid = (lef+rig) >> 1;
		if(val > temp[mid]) lef = mid + 1;
		else if(val < temp[mid]) rig = mid - 1;
		else break;
	}
	return mid;
}

void push_down(int x) {
	if(lazy[x]) {
		lazy[x<<1] = lazy[x<<1|1] = lazy[x];
		lazy[x] = 0;
	}
}

void update(int x, int lef, int rig, int L, int R, int val) {
	if(L<=lef && rig<=R) {
		lazy[x] = val;
		return ;
	}
	push_down(x);
	int mid = (lef+rig) >> 1;
	if(L<=mid) update(x<<1, lef, mid, L, R, val);
	if(mid<R) update(x<<1|1, mid+1, rig, L, R, val);
}

void query(int x, int lef, int rig, int L, int R) {
	if(lef == rig) {
		arr[lef] = lazy[x];
		return ;
	}
	push_down(x);
	int mid = (lef+rig) >> 1;
	if(L<=mid) query(x<<1, lef, mid, L, R);
	if(mid<R) query(x<<1|1, mid+1, rig, L, R);
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int tot = 0, mm = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d %d", &q[i].L, &q[i].R);
			temp[++tot] = q[i].L, temp[++tot] = q[i].R;
		}
		sort(temp+1, temp+1+tot);
		mm = std::unique(temp+1, temp+1+tot) - (temp+1);
		sort(temp+1, temp+1+mm);
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			int L = binsearch(1, mm+1, q[i].L);
			int R = binsearch(1, mm+1, q[i].R);
			update(1, 1, mm, L, R, ++cnt);
		}
		query(1, 1, mm, 1, mm);
		bool vis[MAXN] = { 0 };
		int rs = 0;
		for(int i=1; i<=mm; i++) {
//			printf("%d ", arr[i]);
			if(vis[arr[i]]) continue;
			vis[arr[i]] = true;
			rs ++;
		}
		printf("%d\n", rs);
	}
	return 0;
}


// dfs竟然 WA 掉了 ?????? 写了个大bug ????

//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <algorithm>
//#define MAXN 10086
//using namespace std;

//int n, m;

//int rs[MAXN], arr[MAXN], v1, v2;
//bool vis[MAXN];
//bool tag = false;

//void dfs(int x) {
//	if(x == 3) {
//		if(arr[rs[1]]+arr[rs[2]]==m && arr[rs[1]]<arr[rs[2]]) {
//			if(!tag) {
//				v1 = arr[rs[1]], v2 = arr[rs[2]];
//				tag = true;
//			} else {
//				if(arr[rs[1]] < v1)
//					v1 = arr[rs[1]], v2 = arr[rs[2]];
//			}
//		}
//		return ;
//	}
//	for(int i=1; i<=n; i++) {
//		if(!vis[i]) {
//			vis[i] = true;
//			rs[x] = i;
//			dfs(x+1);
//			vis[i] = false;
//		}
//	}
//}

//int main() {
//	freopen("test", "r", stdin);
//	
//	scanf("%d %d", &n, &m);
//	for(int i=1; i<=n; i++) {
//		scanf("%d", arr+i);
////		rs[i] = i;
//	} 
//	
//	dfs(1);
//	if(tag)
//		printf("%d %d\n", v1, v2);
//	else 
//		printf("No Solution\n");
//	
//	return 0;
//}


/** 
// 超时 解决办法 排好序后用二分查找这两个数
#include <iostream>
#define MAXN 9999999
using namespace std;

int n, m, arr[MAXN];

int main() {
	
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) 
		scanf("%d", arr+i);
	int v1 = 999999, v2 = 999999;
	
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=n; k++) {
			if(i == k) continue ;
			int sum = arr[i] + arr[k];
			if(sum==m && min(arr[i], arr[k]) < v1) {
				v1 = min(arr[i], arr[k]), v2 = max(arr[i], arr[k]);
			}
		}
	}
	if(m == (v1+v2))
		printf("%d %d\n", v1, v2);
	else
		printf("No Solution\n");
	
	return 0;
}
*/



//解决办法 排好序后用二分查找这两个数
#include <iostream>
#include <algorithm>
#define MAXN 9999999
using namespace std;

int n, m, arr[MAXN];

int binsearch(int arr[], int key) { //排好序的arr[]里找key的位置
	int idx = -1;
	int lef = 1, rig = n;
	int mid = (lef+rig) >> 1;
	while(lef <= rig) {
		mid = (lef+rig) >> 1;
		if(arr[mid] == key) { idx = mid; break; }
		else if(arr[mid] < key) 
			lef = mid+1;
		else if(arr[mid] > key)
			rig = mid-1;
	}
	return idx;
}

int main() {
	
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) 
		scanf("%d", arr+i);
	int v1 = 999999, v2 = 999999;
	
	sort(arr+1, arr+1+n);
	bool ok = false;
	for(int i=1; i<=n; i++) {
		v1 = arr[i], v2 = m-v1; // m=15时 如果v1是4 则v2只能是15-4=11
		int idx = binsearch(arr, v2); //查找v2
		if(-1!=idx && idx!=i) { //找到说明ok
			ok = true;
			break;
		}
	}
	
	if(ok)
		printf("%d %d\n", v1, v2);
	else
		printf("No Solution\n");
	
	return 0;
}














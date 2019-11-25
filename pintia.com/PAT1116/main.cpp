//#include <iostream>
//#include <vector>
//#include <stack>
//#include <math.h>
//#include <map>
//#include <set>
//#include <string.h>
//#include <algorithm>
//#define MAXN 100005
//using namespace std;

//int in_list[MAXN], vis[MAXN];
//int the_0 = -1, the_1 = -1;

//int prime[MAXN], pn, n = 10005;
//bool not_prime[MAXN];
//void func() {
//	not_prime[0] = not_prime[1] = true;
//	for(int i=2; i<=n; i++) {
//		if(!not_prime[i]) 
//			prime[pn++] = i;
//		for(int k=0; k<pn && i*prime[k]<=n; k++) {
//			not_prime[i*prime[k]] = true;
//			if(i%prime[k] == 0) 
//				break;
//		}
//	}
//}

//bool is_prime(int x) {
//	int tx = sqrt(x);
//	if(x==1 || x==0) return false;
//	for(int i=2; i<=tx; i++)
//		if(x%i == 0) return false;
//	return true;
//}
//int arr[MAXN];

//int main() {
//	freopen("test", "r", stdin);
//	func();
////	for(int i=0; i<pn; i++) {
////		printf("%d,", prime[i]);
////	}
////	printf("\n");
//	int n;
//	scanf("%d", &n);
//	for(int i=1; i<=n; i++) {
//		int x;
//		scanf("%d", &x);
//		in_list[x] = true;
//		arr[x] = i;
//	}
//	int m;
//	scanf("%d", &m);
//	for( ; m--; ) {
//		int x;
//		scanf("%d", &x);
//		printf("%04d: ", x);
//		if(!in_list[x]) {
//			printf("Are you kidding?\n");
//			continue ;
//		}
//		if(vis[x]) {
//			printf("Checked\n");
//			continue ;
//		}
//		vis[x] = true;
////		printf("%04d - %04d %d\n", x, arr[x], is_prime(arr[x]));
//		if(arr[x] == 1) printf("Mystery Award\n");
//		else if(is_prime(arr[x])) printf("Minion\n");
//		else printf("Chocolate\n");
//	}
//	return 0;
//}




#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

int in_list[MAXN], vis[MAXN];
int the_0 = -1, the_1 = -1;

int prime[MAXN], pn, n = 10005;
bool not_prime[MAXN];
void func() {
	not_prime[0] = not_prime[1] = true;
	for(int i=2; i<=n; i++) {
		if(!not_prime[i]) 
			prime[pn++] = i;
		for(int k=0; k<pn && i*prime[k]<=n; k++) {
			not_prime[i*prime[k]] = true;
			if(i%prime[k] == 0) 
				break;
		}
	}
}

int arr[MAXN];

int main() {
	freopen("test", "r", stdin);
	func();
//	for(int i=0; i<pn; i++) {
//		printf("%d,", prime[i]);
//	}
//	printf("\n");
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		in_list[x] = true;
		arr[x] = i;
	}
	int m;
	scanf("%d", &m);
	for( ; m--; ) {
		int x;
		scanf("%d", &x);
		printf("%04d: ", x);
		if(!in_list[x]) {
			printf("Are you kidding?\n");
			continue ;
		}
		if(vis[x]) {
			printf("Checked\n");
			continue ;
		}
		vis[x] = true;
		if(arr[x] == 1) printf("Mystery Award\n");
		else if(not_prime[arr[x]] == false) printf("Minion\n");
		else printf("Chocolate\n");
	}
	return 0;
}



//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string.h>
//#define ll long long int 
//using namespace std;
//int t;
//ll l, r, k;

//ll f(ll i) {
//	if(0<=i && i<k) return 1;
//	ll sum, idx;
//	for(int j=1, idx=i-1; j<=k; j++, idx--) 
//		sum += f(idx);
//	return sum;
//}

//int main(void) {
//	freopen("test", "r", stdin);
//	scanf("%d", &t);
//	for( ; t--; ) {
//		scanf("%lld %lld %lld", &l, &r, &k);
//		int sum = 0;
//		for(ll i=l; i<=r; i++) {
//			sum += f(i) % 2;
//		}
//		printf("%d\n", sum);
//	}
//	
//	return 0;
//}








#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define ll long long int 
using namespace std;
int t;
ll l, r, k;

int main(void) {
	freopen("test", "r", stdin);
	k = 4;
	int arr[11];
	memset(arr, false, sizeof(arr));
	for(int i=0; i<10; i++) {
		if(0<=i && i<=k) arr[i] = 1;
		else {
			for(int j=1; j<=k; j++) {
				arr[i] += arr[i-j];
			}
		}
	}
	int num = arr[9];
	for(int i=0; i<10; i++) {
		num = arr[i];
		while(num) {
			printf("%d", num&1);
			num >>= 1;
		}
	}
//	scanf("%d", &t);
//	for( ; t--; ) {
//		scanf("%lld %lld %lld", &l, &r, &k);
//		
//	}
	return 0;
}

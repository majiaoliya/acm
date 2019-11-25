#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 4096
using namespace std;

double arr1[MAXN], arr2[MAXN], rs[MAXN];

int main() {
	freopen("test", "r", stdin);
	int len1, len2;
	scanf("%d", &len1);
	for(int i=1; i<=len1; i++) {
		int idx;
		scanf("%d", &idx);
		scanf("%lf", arr1+idx);
	}
	scanf("%d", &len2);
	for(int i=1; i<=len2; i++) {
		int idx;
		scanf("%d", &idx);
		scanf("%lf", arr2+idx);
		for(int k=0; k<MAXN; k++) {
			if(arr1[k] != 0) {
				int rs_idx = idx + k;
				rs[rs_idx] += arr1[k]*arr2[idx];
			}
		}
	}
	int count = 0;
	for(int i=0; i<MAXN; i++) {
		if(rs[i] != 0.000) count ++;
	}
	printf("%d", count);
	for(int i=MAXN-1; i>=0; i--) {
		if(rs[i] != 0.000)
			printf(" %d %.1lf", i, rs[i]);
	}
	
	return 0;
}

























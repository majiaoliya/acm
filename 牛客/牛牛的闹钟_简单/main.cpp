#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#define MAXN 105

using namespace std;

int n, m;

struct Node {
	int hh, mm, parse;
	bool operator < (const int& val) const {
#ifdef debug
		if(val == 972 && hh == 16 && mm == 37) {
			printf("<%d < %d> ? %d\n", parse, val, parse < val);
		}
#endif
		return parse < val;
	}
	bool operator == (const Node& other) const {
		return hh == other.hh && mm == other.mm && parse == other.parse;
	}
} a, arr[MAXN];

int cmp(Node& x, Node& y) { return x.parse < y.parse; }

int binsearch(int lef, int rig, int val) {
	int mid;
	while(lef < rig) {
		mid = (lef + rig) >> 1;
		if(val < arr[mid].parse) 
			rig = mid - 1;
		else if(val >= arr[mid].parse)
			lef = mid + 1;
	}
	return mid;
}

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i=0; i<n; i++) {
			scanf("%d %d", &arr[i].hh, &arr[i].mm);
			arr[i].parse = arr[i].hh * 60 + arr[i].mm;
		}
		sort(arr, arr+n, cmp);
		scanf("%d", &m);
		scanf("%d %d", &a.hh, &a.mm);
		a.parse = a.hh * 60 + a.mm;
//		int mm = std::unique(arr, arr+n) - (arr);
		int idx = std::lower_bound(arr, arr+n, a.parse-m) - arr;
		if(arr[idx].parse > a.parse-m) idx --;
		/**
		for(int i=n; i>=1; i--) {
			if(arr[i].parse + m <= a.parse) {
				idx = i;
				break;
			}
		}
		*/
		printf("%d %d\n", arr[idx].hh, arr[idx].mm);
	}
	
	return 0;
}


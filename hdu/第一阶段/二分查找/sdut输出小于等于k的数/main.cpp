#include <iostream>
#include <algorithm>
#include <map>
#define MAXN 10000005
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

int n, m, i, arr[MAXN];
int nmax, nmin, key;
map<int, int> mp;

int main(void) {
	freopen("test", "r", stdin);

	while(~scanf("%d %d", &n, &m)) {
		for(int i=0; i<n; i++) {
			scanf("%d", arr+i);
			mp[arr[i]] ++;
		}
		sort(arr, arr+n);
		int mm = std::unique(arr, arr+n) - arr;
		while(m--) {
			scanf("%d", &key);
			int down = std::lower_bound(arr, arr+mm, key) - arr;
			int up = std::upper_bound(arr, arr+mm, key) - arr;
			if(down<0 || down>=mm) {
				int rx = mp[arr[up]];
				while(rx--) {
					if(rx) printf(" ");
					printf("%d", arr[up]);
				}
			} else if(up <0 || up>=mm) {
				int rx = mp[arr[down]];
				while(rx--) {
					if(rx) printf(" ");
					printf("%d", arr[rx]);
				}
			} else {
				if(abs(arr[down]-key) == abs(arr[up]-key)) {
					int rx = mp[arr[down]];
					for(int i=0; i<rx; i++) {
						if(i) printf(" ");
						printf("%d", i<rx ? arr[down] : arr[up]);
					}
				} else {
					int val = abs(arr[down]-key) < abs(arr[up]-key) ? down : up;
					int rx = mp[val];
					while(rx--) {
						if(rx) printf(" ");
						printf("%d", val);
					}
				}
			}
			printf("\n");
		}
	}

/**
	n = 10;
	int s[] = { 1, 2, 2, 5, 5, 7, 7, 7, 9, 9 };
	map<int, int> mp;
	for(int i=0; i<n; i++)
		mp[s[i]] ++;
	n = std::unique(s, s+n) - s;
	int lef = std::lower_bound(s, s+n, 6) - s;
	int rig = std::upper_bound(s, s+n, 6) - s;
	printf("lef:%d rig:%d n:%d\n", lef, rig, n);
*/
	return 0;
}

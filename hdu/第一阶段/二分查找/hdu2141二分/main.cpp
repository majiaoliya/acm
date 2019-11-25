#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;

int q, L, N, M;
int a[MAXN], b[MAXN], c[MAXN];

vector<int> ab(0, MAXN);

int binsearch(int key) {
	int lef = 0, rig = ab.size()-1, mid;
	while(lef < rig) {
		mid = (lef + rig) >> 1;
		if(key < ab[mid]) rig = mid - 1;
		else if(key > ab[mid]) lef = mid + 1;
		else break;
	}
	if(ab[mid] == key) return mid;
	else return -1;
}

int main(void) {
	freopen("test", "r", stdin);
	for(int cases=1; ~scanf("%d %d %d", &L, &N, &M); cases++) {
		ab.clear();
		printf("Case %d:\n", cases);
		for(int i=1; i<=L; i++)
			scanf("%d", a+i);
		for(int i=1; i<=N; i++)
			scanf("%d", b+i);
		for(int i=1; i<=M; i++)
			scanf("%d", c+i);

		for(int i=1; i<=L; i++) 
			for(int k=1; k<=N; k++) {
				ab.push_back(a[i]+b[k]);
	//			printf("%d, ", ab.back());
			}
		sort(ab.begin(), ab.end());
		ab.erase(unique(ab.begin(), ab.end()), ab.end());
		scanf("%d", &q);
		while(q--) {
			int x, ok = false;
			scanf("%d", &x);
			for(int i=1; i<=M; i++) {
				int key = x - c[i];
//				if(binsearch(key) != -1) {
//					ok = true;
//					break;
//				}
				int idx = lower_bound(ab.begin(), ab.end(), key) - ab.begin();
				if(ab[idx] == key) {
					ok = true;
					break;
				}
			}
			printf("%s\n", ok ? "YES" : "NO");
		}

	}
	return 0;
}

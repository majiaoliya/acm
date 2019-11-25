#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define MAXN 10000007
using namespace std;

int n, m, q, rs, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	scanf("%d", &q);
	while(q--) {
		int L, R;
		scanf("%d %d", &L, &R);
		if(R-L+1 >= 47) rs ++;
		else if(R-L+1 < 3) continue ;
		else {
			vector<int> v;
			for(int i=L; i<=R; i++)
				v.push_back(arr[i]);
			sort(v.begin(), v.end());
			for(int i=2; i<v.size(); i++) {
				if(v[i-1]+v[i-2] > v[i]) {
					rs ++;
					break;
				}
			}
		}
	}
	printf("%d\n", rs);
	return 0;
}

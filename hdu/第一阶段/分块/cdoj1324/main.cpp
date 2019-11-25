#include <iostream>
#include <math.h>
#include <algorithm>
#define MAXN ((int)1e5+7)
#define ll long long int
using namespace std;

ll n, q, arr[MAXN];
ll block, num, Max[MAXN], l[MAXN], r[MAXN], belong[MAXN];
void build() {
	block = sqrt(n);
	num = n/block;
	if(n%block) num ++;
	for(int i=1; i<=num; i++)
		l[i] = (i-1)*block+1, r[i] = i*block;
	r[num] = n;
	for(int i=1; i<=n; i++)
		belong[i] = (i-1)/block+1;
	for(int i=1; i<=num; i++)
		for(int k=l[i]; k<=r[i]; k++)
			Max[i] = max(Max[i], arr[k]);
}

void update(int x, int y) {
	arr[x] += y;
	Max[belong[x]] = max(Max[belong[x]], arr[x]);
}

ll query(int x, int y) {
	ll ans = 0;
	if(belong[x] == belong[y]) {
		for(int i=x; i<=y; i++) ans = max(ans, arr[i]);
		return ans;
	}
	for(int i=x; i<=r[belong[x]]; i++) ans = max(ans, arr[i]);
	for(int i=belong[x]+1; i<belong[y]; i++) ans = max(ans, Max[i]);
	for(int i=l[belong[y]]; i<=y; i++) ans = max(ans, arr[i]);
	return ans;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%lld %lld", &n, &q);
	build();
	for(int i=0; i<q; i++) {
		int cmd, x, y;
		scanf("%d %d %d", &cmd, &x, &y);
		if(cmd == 1) update(x, y);
		else printf("%lld\n", query(x, y));
	}
	return 0;
}

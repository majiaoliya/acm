#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define MAXN 100005
#define ll long long int
using namespace std;

ll n, q, arr[MAXN];
ll Max[MAXN], l[MAXN], r[MAXN], belong[MAXN], block, num, Sum[MAXN];

void build() {
	block = sqrt(n); //每块的大小为根号n
	num = n/block; //共有num块
	if(n%block) num++;
	for(int i=1; i<=num; i++) //设置每个块的左右区间
		l[i] = (i-1)*block+1, r[i] = i*block;
	r[num] = n; //最后一块的右边为n
	for(int i=1; i<=n; i++) { //设置每一个arr[i]属于那一块 和更新每一块的最大值,区间和
		belong[i] = (i-1)/block+1;
		Max[belong[i]] = max(Max[belong[i]], arr[i]);
		Sum[belong[i]] += arr[i];
	}
}

void change(ll x, ll y) { //更新一个块的最大值,区间和
	Max[belong[x]] = Sum[belong[x]] = 0;
	for(int i=x; i<=y; i++) {
		Max[belong[x]] = max(Max[belong[x]], arr[i]);
		Sum[belong[x]] += arr[i];
	}
}

void update(ll x, ll y) {
	if(belong[x] == belong[y]) {
		for(int i=x; i<=y; i++) arr[i] = sqrt(arr[i]);
		change(l[belong[x]], r[belong[y]]);
		return ;
	}
	for(int i=x; i<=r[belong[x]]; i++) arr[i] = sqrt(arr[i]);
	change(l[belong[x]], r[belong[x]]);
	for(int i=belong[x]+1; i<belong[y]; i++) 
		if(Max[i] > 1) {
			Max[i] = Sum[i] = 0;
			for(int k=l[i]; k<=r[i]; k++) {
				arr[k] = sqrt(arr[k]);
				Max[i] = max(Max[i], arr[k]);
				Sum[i] += arr[k];
			}
		}
	for(int i=l[belong[y]]; i<=y; i++) arr[i] = sqrt(arr[i]);
	change(l[belong[y]], r[belong[y]]);
}

ll query(ll x, ll y) {
	ll ans = 0;
	if(belong[x] == belong[y]) { //[L, R] L和R在同一块里的情况
		for(int i=x; i<=y; i++) ans += arr[i];
		return ans;
	}
	for(int i=x; i<=r[belong[x]]; i++) ans += arr[i]; //左边
	for(int i=belong[x]+1; i<belong[y]; i++) ans += Sum[i]; //中间
	for(int i=l[belong[y]]; i<=y; i++) ans += arr[i]; //右边
	return ans;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%lld", &n);
	for(int i=1; i<=n; i++) scanf("%lld", arr+i);
	build();
	scanf("%lld", &q);
	for(int i=1; i<=q; i++) {
		ll cmd, x, y;
		scanf("%lld %lld %lld", &cmd, &x, &y);
		if(x > y) swap(x, y);
		if(cmd) printf("%lld\n", query(x, y));
		else update(x, y);
	}
	return 0;
}

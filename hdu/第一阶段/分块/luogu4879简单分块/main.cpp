#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#define MAXN ((int)5e5+7)
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

ll n, m, L = 1, R = MAXN-5, idx, val;
ll arr[MAXN], belong[MAXN], l[MAXN], r[MAXN], cnt[MAXN], sum[MAXN], num, block;
bool vis[MAXN];
char cmd;

void build() {
	block = sqrt(R);
	num = R / block;
	if(R % block) num ++;
	for(int i=1; i<=num; i++)
		l[i] = (i-1)*block+1, r[i] = i*block;
	r[num] = R;
}

void insert(ll idx, ll val) {
	if(vis[idx]) {
		sum[belong[idx]] -= arr[idx];
		sum[belong[idx]] += val;
		arr[idx] = val;
	} else {
		sum[belong[idx]] += val;
		cnt[belong[idx]] ++;
		arr[idx] = val;
		vis[idx] = true;
	}
}

void change(ll idx, ll val) {
	if(!vis[idx]) return ;
	arr[idx] -= val;
	sum[belong[idx]] -= val;
}

ll query() {
	ll ans = 0;
	for(int i=1; i<=num; i++) ans += sum[i];
	return ans;
}

void del(ll x) {
	ll k = 1;
	while(x-cnt[k] > 0) x-=cnt[k], k++;
	for(int i=l[k]; i<=r[k]; i++) {
		if(vis[i]) --x;
		if(!x) {
			cnt[k] --;
			vis[i] = false;
			sum[belong[i]] -= arr[i];
			arr[i] = 0;
			break;
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif


	scanf("%lld %lld ", &n, &m);
	build();
	for(int i=1; i<=R; i++) {
		belong[i] = (i-1)/block + 1;
		if(i > n) continue ;
		scanf("%lld ", arr+i);
		sum[belong[i]] += arr[i];
		vis[i] = true;
		cnt[belong[i]] ++;
	}
	ll maxn = n;
	while(m--) {
		scanf("%c ", &cmd);
//		forarr(arr, 1, maxn, "arr");
		if(cmd == 'Q') printf("%lld\n", query());
		if(cmd == 'C') {
			scanf("%lld %lld ", &idx, &val);
			change(idx, val);
		} else if(cmd == 'I') {
			scanf("%lld %lld ", &idx, &val);
			insert(idx, val);
			maxn = max(maxn, idx);
		} else if(cmd == 'D') {
			ll x;
			scanf("%lld ", &x);
			del(x);
		}
	}


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


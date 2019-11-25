#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)5e5+7)
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

ll n, L, R;
ll cnt[MAXN<<2], a[MAXN];
vector<ll> b(MAXN, 0);
map<ll, ll> mp;

void push_up(ll rt) { cnt[rt] = cnt[rt<<1] + cnt[rt<<1|1]; }

void build(ll rt, ll lef, ll rig) {
	if(lef == rig) {
		cnt[rt] = mp[b[lef]];
		return ;
	}
	ll mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}

void insert(ll rt, ll lef, ll rig, ll idx) {
	if(lef == rig) {
		cnt[rt] ++;
		return ;
	}
	ll mid = (lef + rig) >> 1;
	if(idx <= mid) insert(rt<<1, lef, mid, idx);
	else insert(rt<<1|1, mid+1, rig, idx);
	push_up(rt);
}

ll search(ll rt, ll lef, ll rig, ll k) {
	if(lef == rig) return lef;
	ll mid = (lef + rig) >> 1;

	//注意是 k<=cnt[rt<<1] 不是lef
	if(k <= cnt[rt<<1]) return search(rt<<1, lef, mid, k);
	else return search(rt<<1|1, mid+1, rig, k-cnt[rt<<1]);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif


	scanf("%lld ", &n);
	for(int i=1; i<=n; i++) {
		scanf("%lld ", a+i);
		b[i] = a[i];
		mp[a[i]] ++;
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	L = 1, R = b.size();
//	build(1, L, R);
	for(int i=1; i<=n; i++) {
		ll idx = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		insert(1, L, R, idx);
		if(i & 1) {
			ll ans = search(1, L, R, (i+1)>>1);
			printf("%lld\n", b[ans]);
		}
	}



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


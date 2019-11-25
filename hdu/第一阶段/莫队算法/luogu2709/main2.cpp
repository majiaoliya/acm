//#include <iostream>
//#include <math.h>
//#include <algorithm>
//#define MAXN 100005
//using namespace std;
//
//int n, m, K, arr[MAXN], pos[MAXN];
//long long ans[MAXN];
//int cnt[MAXN]; 
//long long res;
//struct Q {
//	int lef, rig, idx;
//} q[MAXN];
//
//void add(int n) { 
//	cnt[arr[n]]++; 
//	res += (cnt[arr[n]])*cnt[arr[n]] - (cnt[arr[n]]-1)*(cnt[arr[n]]-1);
//}
//
//void sub(int n) {
//	cnt[arr[n]]--;
//	res -= (cnt[arr[n]]+1)*cnt[arr[n]+1] - (cnt[arr[n]])*(cnt[arr[n]]);
//}
//
//int main(void) {
//	freopen("test", "r", stdin);
//	scanf("%d %d %d\n", &n, &m, &K);
//	int siz = sqrt(n);
//	for(int i=0; i<n; i++) scanf("%d", arr+i), pos[i]=i/siz;
//	for(int i=0; i<m; i++) {
//		scanf("%d %d", &q[i].lef, &q[i].rig);
//		q[i].idx = i;
//	}
//	sort(q, q+m, [](Q x, Q y) {
//			return pos[x.lef]==pos[y.lef] ? x.rig<y.rig : pos[x.lef]<pos[y.lef];
//			});
//	int l = 1, r = 0;
//	for(int i=0; i<m; i++) {
//		while(q[i].lef<l) add(--l);
//		while(q[i].rig>r) add(++r);
//		while(q[i].lef>l) sub(l++);
//		while(q[i].rig<r) sub(r--);
//		ans[q[i].idx] = res;
//	}
//	for(int i=0; i<m; i++)
//		printf("%lld\n", ans[i]);
//	return 0;
//}


























#include <iostream>
#include <math.h>
#include <algorithm>
#define MAXN 100005
#define ll long long int
using namespace std;
int n, m, k, arr[MAXN];
ll Ans[MAXN], cnt[MAXN];

struct Query {
	int l, r, id, pos;
	bool operator < (const Query& x) const {
		if(pos == x.pos) return r<x.r;
		return pos < x.pos;
	}
} query[MAXN];

inline int read() {
	int f = 1, x = 0;
	char ch;
	do {
		ch = getchar();
		if(ch == '-') f = -1;
	} while(ch<'0' || ch>'9');
	do {
		x = x*10+ch-'0'; ch = getchar();
	} while(ch>='0' && ch<='9');
	return x*f;
}

int main(void) {
	freopen("test", "r", stdin);
//	n = read(), m = read(), k = read();
	scanf("%d %d %d", &n, &m, &k);
	int siz = sqrt(n);
	for(int i=1; i<=n; i++) arr[i] = read();
	for(int i=1; i<=m; i++) {
//		query[i].l = read(), query[i].r = read();
		scanf("%d %d", &query[i].l, &query[i].r);
//		printf("%d %d\n", query[i].l, query[i].r);
		query[i].id = i;
		query[i].pos = (query[i].l-1)/siz+1;
	}
	sort(query+1, query+1+m);
	int l = 1, r = 0;
	ll ans = 0;
	for(int i=1; i<=m; i++) {
		while(l>query[i].l) l--, cnt[arr[l]]++, ans+=2*cnt[arr[l]]-1;
		while(r<query[i].r) r++, cnt[arr[r]]++, ans+=2*cnt[arr[r]]-1;
		while(l<query[i].l) cnt[arr[l]]--, ans-=2*cnt[arr[l]]+1, l++;
		while(r>query[i].r) cnt[arr[r]]--, ans-=2*cnt[arr[r]]+1, r--;
		Ans[query[i].id] = ans;
	}
	for(int i=1; i<=m; i++) printf("%lld\n", Ans[i]);
	return 0;
}


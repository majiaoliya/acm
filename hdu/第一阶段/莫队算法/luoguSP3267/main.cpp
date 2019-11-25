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

int n, m, arr[MAXN];

struct Query {
	int l, r, id, pos;
	bool operator < (const Query& o) const {
		if(l)
	}
} q[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", arr+i);
	scanf("%d", &m);
	int siz = sqrt(n); //分成根号n块
	for(int i=0; i<m; i++) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].pos = q[i].l / siz;
		q[i].id = i;
	}
	sort(q, q+m);
	return 0;
}


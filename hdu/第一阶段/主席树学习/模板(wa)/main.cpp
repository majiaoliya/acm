#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN ((int)2e5+7)
using namespace std;

int n, q; //n个数, q个询问

int a[MAXN];
vector<int> v;
inline int getid(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

struct Node {
	int l, r, sum;
} hjt[MAXN*40];

int cnt, root[MAXN];

//当前节点维护[l, r]
//插入一个p
void insert(int l, int r, int pre, int& now, int p) {
	hjt[++cnt] = hjt[pre];
	now = cnt;
	hjt[now].sum ++;
	if(l == r) return ; //叶子
	int mid = (l + r) >> 1;
	if(p <= mid) insert(l, mid, hjt[pre].l, hjt[now].l, p);
	else insert(mid+1, r, hjt[pre].r, hjt[now].r, p);
}

int query(int l, int r, int L, int R, int k) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	int tmp = hjt[hjt[R].l].sum - hjt[hjt[L].l].sum;
	if(k <= tmp) return query(l, mid, hjt[L].l, hjt[R].l, k);
	else return query(mid+1, r, hjt[L].r, hjt[R].r, k-tmp);
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &q);
	
	for(int i=1, x; i<=n; i++) {
		scanf("%d", &x);
		a[i] = x;
		v.push_back(x);
	}
	sort(v.begin(), v.end()); //先离散化
	v.erase(std::unique(v.begin(), v.end()), v.end());
	for(int i=1; i<=n; i++)
		insert(1, n, root[i-1], root[i], getid(a[i]));
#ifdef debug
	for(auto x : v)
		printf("[%d], ", x);
	printf("\n");
	for(int i=1; i<=cnt; i++) {
		printf("[i:%d  l:%d  r:%d  sum:%d]\n", i, hjt[i].l, hjt[i].r, hjt[i].sum);
	}
#endif
	while(q--) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", v[query(1, n, root[l-1], root[r], k)-1]);
	}
	return 0;
}

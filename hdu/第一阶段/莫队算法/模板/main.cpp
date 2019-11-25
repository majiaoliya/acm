#include <iostream>
#include <math.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

int len, n, m, arr[MAXN];
int pos[MAXN], ans[MAXN], res;

struct Q {
	int l, r, k;
} q[MAXN];

void add(int idx) { res += arr[idx]; }
void sub(int idx) { res -= arr[idx]; }

int main(void) {
	// n个数字, m个询问, [L, R]
	int n, m, L, R;
	cin >> n >> m;
	//先分块
	int siz = sqrt(n); //每块根号n
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		pos[i] = i/siz;
	}
	for(int i=0;  i<m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].k = i;
	}
	sort(q, q+m, [](Q x, Q y) {
		//在同一个块按r排
		//不在同一个块按块排
		return pos[x.l] == pos[y.l] ? x.r<y.r : pos[x.l]<pos[y.l];
	});
	int l=1, r=0;
	for(int i=0; i<m; i++) {
		while(q[i].l<l) add(--l);
		while(q[i].r>r) add(++r);
		while(q[i].l>l) sub(l++);
		while(q[i].r<r) sub(i--);
		ans[q[i].k] = res;
	}
	for(int i=0; i<m; i++)
		cout << ans[i] << endl;
	return 0;
}

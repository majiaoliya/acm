#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define debug(x) cerr << #x << "=" << x << endl;
const int MAXN = 500000 + 10;
int n,m,lover[MAXN],sep[MAXN],a[MAXN];
struct Node{
    long long sum;
    int cnt;
}tree[MAXN * 4]; 

void update(int rt) {
    tree[rt].sum = tree[rt*2].sum + tree[rt*2+1].sum;
    tree[rt].cnt = tree[rt*2].cnt + tree[rt*2+1].cnt;
}

void build(int rt, int l, int r) {
    int mid = l+r>>1;
    if(l == r) {
        if(a[l])    
            tree[rt].cnt = 1;
        tree[rt].sum = a[l];
        return;
    }
    build(rt*2, l, mid);
    build(rt*2+1, mid+1, r);
    update(rt);
}

void change(int rt, int l, int r, int x, int y) {
    if(l == r) {
        tree[rt].sum -= y;
        return;
    }
    int mid = l+r>>1;
    if(x <= mid) change(rt*2, l, mid, x, y);
    else change(rt*2+1, mid+1, r, x, y);//单点只需else 若是区间则需y >= mid + 1
    update(rt);
}

void insert(int rt, int l, int r, int x, int y) {
    if(l == r) {
        tree[rt].sum = y;
        tree[rt].cnt = 1;
        return;
    }
    int mid = l+r>>1;
    if(x <= mid) insert(rt*2, l, mid, x, y);
    else insert(rt*2+1, mid+1, r, x, y);
    update(rt);
}

void del(int rt, int l, int r, int k) {
    if(l == r) {
        tree[rt].cnt = 0;
        tree[rt].sum = 0;
        return;
    }
    int mid = l+r>>1;
    if(k <= tree[rt*2].cnt) del(rt*2, l, mid, k);
    else del(rt*2+1, mid+1, r, k-tree[rt*2].cnt);
    update(rt);
}

int main() {
	freopen("test", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    int maxr = MAXN - 10;
    build(1, 1, maxr);
    for(int i=1; i<=m; i++) {
        char ccc;
        cin >> ccc;
        if(ccc == 'C') {
            int x,y;    
            scanf("%d %d", &x, &y);
            change(1, 1, maxr, x, y);
        } else if(ccc == 'I') {
            int x,y;
            scanf("%d %d", &x, &y);
            insert(1, 1, maxr, x, y);
        } else if(ccc == 'D') {
            int x;
            scanf("%d", &x);
            del(1, 1, maxr, x);
        } else if(ccc == 'Q') {
            printf("%lld\n", tree[1].sum);
        }
    }
    return 0;
}

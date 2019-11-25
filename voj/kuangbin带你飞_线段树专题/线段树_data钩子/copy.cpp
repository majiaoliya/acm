#include <iostream>
#include <string.h>
#define MAXN 100005
#define ll long long 
using namespace std;

int n, m;

int sum[MAXN<<2], lazy[MAXN<<2], arr[MAXN];

void init(int n) {
    for(int i=1; i<=n; i++)
        arr[i] = 1;
}

void push_up(int node) {
    sum[node] = sum[node<<1] + sum[node<<1|1];
}

void push_down(int node, int len) {
    if(lazy[node]) {
        lazy[node<<1] = lazy[node<<1|1] = lazy[node];
        sum[node<<1] = lazy[node]*(len-(len>>1));
        sum[node<<1|1] = lazy[node]*(len>>1);
        lazy[node] = 0;
    }
}

void build(int node, int start, int end) {
    lazy[node] = 0;
    if(start == end) {
        sum[node] = arr[start];
        return ;
    }
    int mid = (start+end)/2, lef = node<<1, rig = node<<1|1;
    build(lef, start, mid);
    build(rig, mid+1, end);
    push_up(node);
}

void update(int node, int start, int end, int l, int r, int val) {
    if(start>=l && end<=r) {
        lazy[node] = val;
        sum[node] = val*(end-start+1);
        return ;
    }
    if(start == end) return ;
    push_down(node, end-start+1);
    int mid = (start+end)/2, lef = node<<1, rig = node<<1|1;
    if(l<=mid)
        update(lef, start, mid, l, r, val);
    if(r>mid)
        update(rig, mid+1, end, l, r, val);
    push_up(node);
}

int main(void) {
    freopen("test", "r", stdin);
    int t;
    scanf("%d", &t);
    int count = 1;
    for( ; t--; ) {
        scanf("%d", &n);
        init(n);
        build(1, 1, n);
        scanf("%d", &m);
        for( ; m--; ) {
            int l, r, val;
            scanf("%d %d %d", &l, &r, &val);
            update(1, 1, n, l, r, val);
        }
        printf("Case %d: The total value of the hook is %d.\n",
        count++, sum[1]);
//        update(1, 1, n, 1, 5, 2);
//        update(1, 1, n, 5, 9, 3);
//        for(int i=1; i<=n<<2; i++) {
//            printf("sum[%d] sum:%d\n", i, sum[i]);
//        }
//        for(int i=1; i<=n; i++) 
//            printf("arr[%d] = %d\n", i, arr[i]);
    }    
    return 0;
}

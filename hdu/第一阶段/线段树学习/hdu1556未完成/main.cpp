#include <iostream>
#include <string.h>
#define MAXN 100010
#define ll long long int
using namespace std;

//ll n, m;
//ll sum[MAXN<<2], add[MAXN<<2];

//void push_up(ll node) {
//	sum[node] = sum[node<<1] + sum[node<<1|1];
//}

//void push_down(ll node, ll len) {
//	if(add[node]) {
//		add[node<<1] += add[node];
//		add[node<<1|1] += add[node];
//		sum[node<<1] += add[node]*(len-(len>>1));
//		sum[node<<1|1] += add[node]*(len>>1);
//		add[node] = 0;
//	}
//}

//void build(ll node, ll start, ll end) {
//	add[node] = 0;
//	if(start == end) {
//		sum[node] = arr[start];
//		return ;
//	}
//	ll mid = (start+end)>>1, lef = node<<1, rig = node<<1|1;
//	build(lef, start, mid);
//	build(rig, mid+1, end);
//	push_up(node);
//}

//void update(ll node, ll start, ll end, ll l, ll r, ll val) {
//	if(start>=l && end<=r) {
//		add[node] += val;
//		sum[node] += val*(end-start+1);
//		return ;
//	}
//	push_down(node, end-start+1);
//	ll mid = (start+end)>>1, lef = mid<<1, rig = mid<<1|1;
//	if(l<=mid)
//		update(lef, start, mid, l, r, val);
//	if(r>mid)
//		update(rig, mid+1, end, l, r, val);
//	push_up(node);
//}

//ll query(ll node, ll start, ll end, ll l, ll r) {
//	if(start == end) { return sum[start]; }
//}

ll arr[MAXN], sum[MAXN<<2], lazy[MANX<<2];

void push_up(int node) {
	sum[node] = sum[node<<1] + sum[node<<1|1];
}

void push_down(int node) {
	if(lazy[node]) {
		lazy[node<<1] += lazy[node];
		lazy[node<<1|1] += lazy[node];
		lazy[node] = 0;
	}
}

void build(int node, int start, int end) {
	lazy[node] = 0;
	if(start == end) {
		sum[node] = arr[start];
		return ;
	}
	int mid = (start+end)>>1;
	build(node<<1, start, mid);
	build(node<<1|1, mid+1, end);
	push_up(node);
}

void update(int node, int start, int end, int l, int r, int val) {
	if(start>=l && end<=r) {
		lazy[node] += val;
		return ;
	}
	push_down(node);
	int mid = (start+end)>>1, lef = node<<1, rig = node<<1|1;
	if(l<=mid)
		update(lef, start, mid, l, r, val);
	if(r>mid)
		update(rig, mid+1, end, l, r, val);
	push_up(node);
}

void query(int node, int start, int end, int l, int r) {
	if(start>=l && end)
}

int main(void) {
	freopen("test", "r", stdin);
	
	scanf("%lld %lld", &n, &m);
	for(ll i=1; i<=n; i++)
		scanf("%lld", arr+i);
	char buf[4];
	build(1, 1, n);
	for( ; m--; ) {
		scanf("%s", buf);
		if(buf[0] == 'Q') {
			ll l, r;
			scanf("%lld %lld", &l, &r);
			printf("%lld\n", query(1, 1, n, l, r));
		} else if(buf[0] == 'C') {
			ll l, r, val;
			scanf("%lld %lld %lld", &l, &r, &val);
			update(1, 1, n, l, r, val);
		}
	}
	
	return 0;
}












////
////  POJ3468.cpp
////  线段树
////
////  Created by TimmyXu on 13-8-12.
////  Copyright (c) 2013年 TimmyXu. All rights reserved.
////

//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <cstring>
//#include <algorithm>

//using namespace std;

//const int maxn = 100000 + 10;

//struct node
//{
//    int l,r,mid;
//    long long len,add,sum;
//}tree[maxn<<2];

//int n,m,le,ri,c;
//char ch;

//void buildtree(int root,int l,int r)
//{
//    tree[root].l = l;
//    tree[root].r = r;
//    tree[root].mid = (l+r)/2;
//    tree[root].add = 0;
//    tree[root].len = r-l+1;
//    if (l == r)
//    {
//        scanf("%lld",&tree[root].sum);
//        return;
//    }
//    buildtree(root<<1,l,(l+r)/2);
//    buildtree(root<<1|1,(l+r)/2+1,r);
//    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
//}

//void update(int root,int l,int r,int c)
//{
//    if (l <= tree[root].l && tree[root].r <= r)
//    {
//        tree[root].add += c;
//        tree[root].sum += c*tree[root].len;
//        return;
//    }
//    if (tree[root].add!=0)
//    {
//        tree[root<<1].add += tree[root].add;
//        tree[root<<1].sum += tree[root].add*tree[root<<1].len;
//        tree[root<<1|1].add += tree[root].add;
//        tree[root<<1|1].sum += tree[root].add*tree[root<<1|1].len;
//        tree[root].add = 0;
//    }
//    if (l <= tree[root].mid) update(root<<1,l,r,c);
//    if (tree[root].mid < r) update(root<<1|1,l,r,c);
//    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
//}

//long long getsum(int root,int l,int r)
//{
//    if (l <= tree[root].l && tree[root].r <= r)
//        return tree[root].sum;
//    if (tree[root].add!=0)
//    {
//        tree[root<<1].add += tree[root].add;
//        tree[root<<1].sum += tree[root].add*tree[root<<1].len;
//        tree[root<<1|1].add += tree[root].add;
//        tree[root<<1|1].sum += tree[root].add*tree[root<<1|1].len;
//        tree[root].add = 0;
//    }
//    long long ans = 0;
//    if (l <= tree[root].mid) ans += getsum(root<<1,l,r);
//    if (tree[root].mid < r) ans += getsum(root<<1|1,l,r);
//    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
//    return ans;
//}

//int main()
//{
//	freopen("test", "r", stdin);
//    scanf("%d%d",&n,&m);
//    buildtree(1,1,n);
//    while (m--)
//    {
//        scanf("%c%c%d%d",&ch,&ch,&le,&ri);
//        if (ch == 'Q')
//            printf("%lld\n",getsum(1,le,ri));
//        else
//        {
//            scanf("%d",&c);
//            update(1,le,ri,c);
//        }
//    }
//}

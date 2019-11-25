/*
HDU 1540 Tunnel Warfare
题义是对于一段线段，D x 表示破坏x点，
R 表示回复最近一次被破坏的点，Q x表示
询问以x点为中心的两头的最长的连续区间。
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 50005

int n, m;
int llen[MAXN<<2]; // [lef,mid] 左边最大连续长度
int rlen[MAXN<<2]; // [mid+1, rig] 右边最大连续长度
int mlen[MAXN<<2]; // [lef, rig] 整个区间的最大连续长度

void push_up(int x) {
	llen[x] = llen[x<<1];
	rlen[x] = rlen[x<<1|1];
	mlen[x] = 
}

void push_down(int x) {
	if(lazy[x] != -1) {
		lazy[x<<1] = lazy[x];
		lazy[x<<1|1] = lazy[x];
		lazy[x] = -1;
	}
}

void build(int x, int lef, int rig, int L, int R) {
	len[x] = rig-lef+1;
	lazy[x] = -1; //lazy初始化
	if(lef == rig) return ;
	int mid = (lef+rig) >> 1;
	build(x<<1, lef, mid, L, R);
	build(x<<1|1, mid+1, rig, L, R);
}

void update(int x, int lef, int rig, int L, int R, int val) {
	if(lef == rig) {
		if(val == 0) 
			mlen[x] = llen[x] = rlen[x] = 0;
		else
			mlen[x] = llen[x] = rlen[x] = 1;
		return ;
	}
	push_down(x);
	int mid = (lef+rig) >> 1;
	if(L<=mid) update(x<<1, lef, mid, L, R, val);
	if(mid<R) update(x<<1|1, mid+1, rig, L, R, val);
	push_up(x);
}

int main() {	
	freopen("test", "r", stdin);
    for( ; EOF != scanf("%d %d", &n, &m); ) {
    	char cmd[4];
    	scanf("%s", cmd);
    	if(cmd[0] == 'D') { //
    		
    	} else if(cmd[0] == 'Q') {
    		
    	} else {
    		
    	}
    }
    return 0;
}

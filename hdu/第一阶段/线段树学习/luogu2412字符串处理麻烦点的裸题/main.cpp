#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100050
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

/**
 * luogu2253
 * 求最长连续交错01子串 copy的模板
 */

int n, m;
struct Node {
	int L, R, Mid;
	int Lf, Rf, len;
} Tree[MAXN<<2];

inline void pushup(int rt)
{
    Tree[rt].L=Tree[rt<<1].L;
    Tree[rt].R=Tree[rt<<1|1].R;
    Tree[rt].Lf=Tree[rt<<1].Lf;
    Tree[rt].Rf=Tree[rt<<1|1].Rf;
    Tree[rt].Mid=max(Tree[rt<<1].R,Tree[rt<<1].Mid);
    Tree[rt].Mid=max(Tree[rt].Mid,Tree[rt<<1|1].L);
    Tree[rt].Mid=max(Tree[rt].Mid,Tree[rt<<1|1].Mid);
    if(Tree[rt<<1].Rf!=Tree[rt<<1|1].Lf)
    {
        Tree[rt].Mid=max(Tree[rt<<1].R+Tree[rt<<1|1].L,Tree[rt].Mid);
        if(Tree[rt<<1].L==Tree[rt<<1].len)
            Tree[rt].L+=Tree[rt<<1|1].L;
        if(Tree[rt<<1|1].R==Tree[rt<<1|1].len)
            Tree[rt].R+=Tree[rt<<1].R;
    }
    return;
}

void Build(int rt,int l,int r)
{
    Tree[rt].len=r-l+1;
    if(l==r)
    {
        Tree[rt].L=Tree[rt].R=Tree[rt].Mid=1;
        Tree[rt].Lf=Tree[rt].Rf=0;
        return;
    }
    int m=(l+r)>>1;
    Build(rt<<1,l,m);
    Build(rt<<1|1,m+1,r);
    pushup(rt);
    return;
}

void update(int rt, int lef, int rig, int k) {
	if(lef == rig) {
		Tree[rt].Lf = Tree[rt].Rf = (Tree[rt].Rf+1) % 2;
		return ;
	}
	int mid = (lef + rig) >> 1;
	if(k <= mid) update(rt<<1, lef, mid, k);
	else update(rt<<1|1, mid+1, rig, k);
	pushup(rt);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	int N, M, i, x;
	scanf("%d %d ", &N, &M);
	Build(1, 1, N);
	for(int i=1; i<=M; i++) {
		scanf("%d ", &x);
		update(1, 1, N, x);
		printf("%d\n", Tree[1].Mid);
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


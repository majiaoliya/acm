#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mid int m = (l + r) >> 1
int sum[MAXN<<2];
int lazy[MAXN<<2];
void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
    if(lazy[rt])
    {
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        sum[rt<<1] = lazy[rt] *(m-(m>>1));
        sum[rt<<1|1] = lazy[rt] *(m>>1);
        lazy[rt] = 0;
    }
}
void build(int l,int r,int rt)
{
    lazy[rt] = 0;
    sum[rt] = 1;
    if(l==r)
        return;
    mid;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L <= l&& r <= R){
        lazy[rt] = c;
        sum[rt] = c * (r - l + 1);
        return;
    }
    PushDown(rt,r-l+1);
    mid;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    PushDown(rt,r-l+1);
    int ret = 0;
    mid;
    if(L<=m) ret += query(L,R,lson);
    if(R>m) ret += query(L,R,rson);
    return ret;
}
int main()
{
	freopen("test", "r", stdin);
    ios::sync_with_stdio(false);
    int T,n,q,a,b,c,casenum;
    while(cin>>T){
        casenum = 0;
        while(T--){
            cin>>n>>q;
            build(1,n,1);
            for(int i = 0;i<q;i++){
                cin>>a>>b>>c;
                update(a,b,c,1,n,1);
            }
            for(int i = 1;i<=20;i++)
                cout<<sum[i]<<endl;
            printf("Case %d: The total value of the hook is %d.",++casenum,sum[1]);
        }
    }

}


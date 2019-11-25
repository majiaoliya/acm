/***
hdu4267分组线段树
题目大意：对于给定区间[a,b]的数(i-a)%k==0加上c，最后单点查询。
解题思路：分组为[a,b]区间内除k余m的分为一组。这样按组来更新就好了。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
const int maxn=50010;
 
int tree[maxn*4][55];
int flag[maxn*4];
int b[11][11],num[maxn];
 
void build(int l,int r,int root)
{
    flag[root]=0;
    for(int i=0;i<55;i++)
    {
        tree[root][i]=0;
    }
    if(l==r)return;
    int mid=(l+r)/2;
    build(l,mid,root<<1);
    build(mid+1,r,root<<1|1);
}
 
void push_down(int root)
{
    if(flag[root])
    {
        flag[root<<1|1]=flag[root<<1]=flag[root];
        flag[root]=false;
        for(int i=0;i<55;i++)
        {
            tree[root<<1][i]+=tree[root][i];
            tree[root<<1|1][i]+=tree[root][i];
            tree[root][i]=0;
        }
    }
}
 
int query(int pos,int l,int r,int root)
{
    if(l==r)
    {
        int ret=0;
        for(int i=1;i<=10;i++)
        {
            ret+=tree[root][b[i][pos%i]];
        }
        return ret;
    }
    push_down(root);
    int m=(l+r)/2;
    if(pos<=m)
        return query(pos,l,m,root<<1);
    else
        return query(pos,m+1,r,root<<1|1);
}
 
void update(int mod,int L,int R,int k,int c,int l,int r,int root)
{
    if(L<=l&&r<=R)
    {
       /// printf("*\n");
        tree[root][b[k][mod]]+=c;
        flag[root]=true;
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid)
        update(mod,L,R,k,c,l,mid,root<<1);
    if(mid<R)
        update(mod,L,R,k,c,mid+1,r,root<<1|1);
}
 
int main()
{
	freopen("test", "r", stdin);
    int cnt=0;
    for(int i=1;i<11;i++)///分组
    {
        for(int j=0;j<i;j++)
            b[i][j]=cnt++;
    }
    int n,m;
    while(~scanf("%d",&n))
    {
        build(1,n,1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        scanf("%d",&m);
        while(m--)
        {
            int x;
            scanf("%d",&x);
            if(x==1)
            {
                int u,v,k,c;
                scanf("%d%d%d%d",&u,&v,&k,&c);
                update(u%k,u,v,k,c,1,n,1);
            }
            else
            {
                int pos;
                scanf("%d",&pos);
                printf("%d\n",query(pos,1,n,1)+num[pos]);
            }
        }
    }
    return 0;
}

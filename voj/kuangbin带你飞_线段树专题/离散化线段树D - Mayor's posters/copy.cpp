#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <math.h>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <ctime>
#define INF 0x3f3f3f3f
#define MAXN 100005
#define Mod 1000000007
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int col[MAXN<<3],hsh[MAXN<<3],li[MAXN],ri[MAXN];
int n,vis[MAXN<<3],ans;
void pushdown(int rt)
{
    if(col[rt]!=-1)
    {
        col[rt<<1]=col[rt<<1|1]=col[rt];
        col[rt]=-1;
    }
}
int binsearch(int num,int n,int a[])
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)>>1;
        if(a[mid]==num)
            return mid;
        else if(a[mid]<num)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        col[rt]=c;
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,c,lson);
    if(R>m)
        update(L,R,c,rson);
}
void query(int l,int r,int rt)
{
    if(col[rt]!=-1)
    {
        if(!vis[col[rt]])
            ans++;
        vis[col[rt]]=1;
        return;
    }
    if(l==r)
        return;
    int m=(l+r)>>1;
    query(lson);
    query(rson);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(col,-1,sizeof(col));
        int n,nn=0;
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d",&li[i],&ri[i]);
            hsh[nn++]=li[i];
            hsh[nn++]=ri[i];
        }
        sort(hsh,hsh+nn);
        int m=1;
        for(int i=1; i<nn; ++i)
        {
            if(hsh[i]!=hsh[i-1])
                hsh[m++]=hsh[i];
        }
        for(int i=m-1;i>0;--i)
        {
            if(hsh[i]!=hsh[i-1]+1)
                hsh[m++]=hsh[i-1]+1;
        }
        sort(hsh,hsh+m);
        for(int i=0; i<n; ++i)
        {
            int l=binsearch(li[i],m,hsh);
            int r=binsearch(ri[i],m,hsh);
            update(l,r,i,0,m-1,1);
        }
        memset(vis,0,sizeof(vis));
        ans=0;
        query(0,m-1,1);
        printf("%d\n",ans);
    }
    return 0;
}


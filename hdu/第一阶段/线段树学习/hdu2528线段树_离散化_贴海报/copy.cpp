include<math.h>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=10005;
int n;
int vis[maxn<<3],sum[maxn<<4];
int li[maxn*2],ri[maxn*2],lsh[maxn<<2];
void pushdown(int rt)
{
    sum[rt<<1]=sum[rt];
    sum[rt<<1|1]=sum[rt];
    sum[rt]=-1;
}
void update(int L,int R,int C,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        sum[rt]=C;
        return ;
    }
    if(sum[rt]!=-1)
        pushdown(rt);
    int m=(l+r)>>1;
    if(m>=R) update(L,R,C,l,m,rt<<1);
    else if(L>m) update(L,R,C,m+1,r,rt<<1|1);
    else update(L,m,C,l,m,rt<<1),update(m+1,R,C,m+1,r,rt<<1|1);
}
int ans;
void query(int l,int r,int rt)
{
	if(!vis[sum[rt]]&&sum[rt]!=-1) {
		ans++;
		vis[sum[rt]]=1;
		return ;
	}
    if(l==r)
    {
        return ;
    }
    if(sum[rt]!=-1)
        pushdown(rt);
    int m=(l+r)>>1;
    query(l,m,rt<<1);
    query(m+1,r,rt<<1|1);
}
int main()
{
	freopen("test", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(sum,-1,sizeof(sum));
        memset(vis,0,sizeof(vis));
        int tot=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&li[i],&ri[i]);
            lsh[tot++]=li[i];
            lsh[tot++]=ri[i];
        }
        sort(lsh,lsh+tot);
        int mm=unique(lsh,lsh+tot)-lsh;
        int tt=mm;
        for(int i=1;i<tt;i++)
        {
            if(lsh[i]-lsh[i-1]>1)
                lsh[mm++]=lsh[i-1]+1;
        }
        sort(lsh,lsh+mm);
        for(int i=0;i<n;i++)
        {
            int x=lower_bound(lsh,lsh+mm,li[i])-lsh;
            int y=lower_bound(lsh,lsh+mm,ri[i])-lsh;
            update(x,y,i,0,mm-1,1);
        }
        ans=0;
        query(0,mm-1,1);
        printf("%d\n",ans);
    }
}

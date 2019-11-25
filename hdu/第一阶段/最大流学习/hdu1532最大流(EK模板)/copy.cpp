#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define M 205
#define inf 1e8
int n,m,a,b,c,g[M][M],flow[M],pre[M];
bool vis[M];
int bfs()
{
    memset(vis,false,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++)
        flow[i]=inf;
    vis[1]=true;
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&g[p][i]>0)
            {
                vis[i]=true;
                flow[i]=min(flow[p],g[p][i]);
                pre[i]=p;
                q.push(i);
            }
        }
    }
    if(!vis[n]||n==1) return -1;
    return flow[n];
}
int ek()
{
    int maxflow=0,d,res,temp;
    while((d=bfs())!=-1)
    {
        maxflow+=d;
        temp=n;
        while(temp!=1)
        {
            res=pre[temp];
            g[res][temp]-=d;
            g[temp][res]+=d;
            temp=res;
        }
    }
    return maxflow;
}
int main()
{
    freopen("test","r",stdin);
    while(~scanf("%d%d",&m,&n))
    {
        memset(g,0,sizeof(g));
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            g[a][b]+=c;
        }
        printf("%d\n",ek());
    }
    return 0;
}

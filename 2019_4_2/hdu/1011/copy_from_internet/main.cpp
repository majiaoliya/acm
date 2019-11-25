/**
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
int n,m,len;
int dp[105][105];//dp表示在i点放j人能得到的能量
int bug[105],p[105],vis[105],head[105];
 
struct node
{
    int now,next;
} tree[105];
 
void add(int x,int y)
{
    tree[len].now = y;
    tree[len].next = head[x];
    head[x] = len++;
}
 
void dfs(int root)
{
    int cost,i,j,k,son;
    vis[root] = 1;
    cost = (bug[root]+19)/20;//不足20的部分也要安排一个
    for(i = cost; i<=m; i++)
        dp[root][i] = p[root];//小于cost的无法获得经验
    for(i = head[root]; i!=-1; i = tree[i].next)
    {
        son = tree[i].now;
        if(!vis[son])
        {
            dfs(son);
            for(j = m; j>=cost; j--)
            {
                for(k = 1; j+k<=m; k++)
                {
                    if(dp[son][k])//到达r的有j+k人，如果留在r有j人，则到达后继节点有k人
                        dp[root][j+k] = max(dp[root][j+k],dp[root][j]+dp[son][k]);
                }
            }
        }
    }
}
 
int main()
{
    int i,j,x,y;
    while(~scanf("%d%d",&n,&m),n+m>0)
    {
        for(i = 1; i<=n; i++)
            scanf("%d%d",&bug[i],&p[i]);
        len = 0;
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        for(i = 1; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        if(!m)
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        dfs(1);
        printf("%d\n",dp[1][m]);
    }
 
    return 0;
}
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Room
{
    int bugs;
    int brains;
};
Room rooms[101];
int value[101][101];
int matrix[101][101];
int visited[101];
int n,m;
void dpTree(int u)
{
    visited[u]=1;
    int r=(rooms[u].bugs+19)/20; //这个r表示当前这个房间里需要留几个士兵，即使是1个虫子也需要一个兵。
    for(int i=m;i>=r;i--)
        value[u][i]=rooms[u].brains;//只要在这个房子里留够士兵，那么就可以获得全部的brains
    for(int v=1;v<=n;v++)
    {
        if(matrix[u][v] && !visited[v])//选择当前点相邻的点，并且此边没有访问过，注意只能往下走而不能走回去
        {
            dpTree(v);
            for(int j=m;j>=r;j--)
                for(int k=1;k<=j-r;k++)
                    value[u][j]=max(value[u][j],value[u][j-k]+value[v][k]);
        }//这个状态转移方程的意思是，第u个房间里留j个士兵所获得brains是由在第u个房间里留j-k个士兵，在与之相连的第v个房间里就k个士兵所获得的brains所决定的。一定记住了，当前的状态仅仅由与其相连的点的状态所决定！！！
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==-1)
            break;
        memset(rooms,0,sizeof(rooms));
        memset(matrix,0,sizeof(matrix));
        memset(visited,0,sizeof(visited));
        memset(value,0,sizeof(value));
        for(int i=1;i<=n;i++)
            scanf("%d %d",&rooms[i].bugs,&rooms[i].brains);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            matrix[u][v]=matrix[v][u]=1;
        }
        if(m==0)
        {
            printf("0\n");
            continue;
        }
        dpTree(1);
        printf("%d\n",value[1][m]);
    }
    return 0;
}

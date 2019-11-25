#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    int x,y,step,time;
};
int map[10][10],n,m;
int bx,by;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void bfs()
{
    queue<node>q;
    node t={bx,by,0,6};//起点的状态 
    q.push(t);
    while(!q.empty())
    {
        node p;
        p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            t.x=dx[i]+p.x;
            t.y=dy[i]+p.y;    
            t.step=p.step+1;
            t.time=p.time-1;
            if(t.x>=0&&t.x<n&&t.y>=0&&t.y<m&&t.time>0&&map[t.x][t.y]!=0)//可行走的情况 
            {
                if(map[t.x][t.y]==3)//到达终点，就是最短时间 
                {
                    cout<<t.step<<endl;
                    return ;
                }
                if(map[t.x][t.y]==4)//遇到重置设备 
                {
                    t.time=6;
                    map[t.x][t.y]=0;
                }
                q.push(t);
                printf("row:%d col:%d\n", t.x, t.y);
            }
        } 
    }
    cout<<-1<<endl;//始终没有搜索到终点，不能到达 
    return ;
}
int main()
{
	freopen("test", "r", stdin);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>map[i][j];
                if(map[i][j]==2)
                {
                    bx=i,by=j;//起点 
                }
            }
        }
        bfs();
    }
    return 0;
}

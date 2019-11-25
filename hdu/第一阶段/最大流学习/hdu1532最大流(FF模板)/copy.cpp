//部分源码来自挑战程序设计竞赛1
#include <bits/stdc++.h>
#define MAX_V 210                    //根据题目需求改变
#define INF 0x3f3f3f3f               //定义无穷大值
using namespace std;

struct edge{       //边的定义：终点，边的容量，以及反向边
	int to,cap,rev;
};

vector<edge> G[MAX_V];       //邻接表
int used[MAX_V];            //访问标记数组

int n,m;

void add_edge(int from,int to,int cap){             //添加边的函数
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}

int dfs(int v,int t,int f){                  //dfs求解
	if(v==t)	return f;
	used[v] = 1;
	for(int i = 0;i<G[v].size();i++){
		edge &e=G[v][i];
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){            //求最大流
	int flow=0;
	while(1){
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(f==0)	return flow;
		flow+=f;
	}
}

int main(){
	freopen("test", "r", stdin);
	while(~scanf("%d %d",&n,&m)){
		for(int i = 1;i<=n;i++){
			int t1,t2,t3;
			scanf("%d %d %d",&t1,&t2,&t3);         //输入数据
			add_edge(t1,t2,t3);	
		}
		printf("%d\n",max_flow(1, 2));
		for(int i = 1;i<=n;i++){
			G[i].clear();
		}
	}	
	return 0;
}


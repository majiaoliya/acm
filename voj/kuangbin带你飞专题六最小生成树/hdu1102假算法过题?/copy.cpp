#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 105

int mat[N][N];
int visit[N],fa[N];
struct Path{
    int x,y,d;
    bool operator<(const Path &m) const{
        return d<m.d;
    }
}path[10010];

int getHead(int x)
{
    int a=x;
    while(fa[x]!=x) x=fa[x];
    fa[a]=x;
    return x;
}

bool Union(int x,int y)
{
    int fa_x=getHead(x);
    int fa_y=getHead(y);
    if(fa_x==fa_y) return false;
    else{
        fa[fa_x]=fa_y;
        return true;
    }
}
void swap(int &a,int &b)
{
    if(a<b){
        int temp=a;
        a=b;
        b=temp;
    }
}

int main()
{
	freopen("test", "r", stdin);
    int n,Q,a,b,k,ans;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<N;i++) fa[i]=i;
        memset(visit,0,sizeof(visit));
        k=1,ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) cin>>mat[i][j];
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++) path[k].x=i,path[k].y=j,path[k++].d=mat[i][j];
        }

        cin>>Q;
        for(int i=1;i<=Q;i++){
            cin>>a>>b;
            swap(a,b);
            path[(a-1)*(a-2)/2+b].d=0;
        }

        sort(path+1,path+k);

        int count=0;
        for(int i=0;i<k;i++){
            if(Union(path[i].x,path[i].y)) ans+=path[i].d,count++;
            if(count==n-1) break;//当然这一步是为了做一个优化，让它可以提前跳出循环，
                                 //其实不跳出循环让它一直循环结束也是成立的,只是在找到n-1条边之后，
                                 //Union函数得到的判断均为false因为n个点都进入了同一个集合内
        }
        cout<<ans<<endl;
    }
    return 0;
}

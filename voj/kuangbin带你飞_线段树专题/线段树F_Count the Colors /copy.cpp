/*
题意：在数轴上用不同的颜色画线段，每一次画，可以覆盖上一次的颜色，问你所有操作完之后可以有多少种颜色，每种能看见的颜色的线段数

初步思路：线段树区间染色问题，实际上可以转化为一个区间set问题，每次操作就是进行一个染色

#错误：因为是闭区间，所以实际染色应该是[l,r);而且查询的时候不能在区间查询了，如果这样的话，在一个连续线段上的染色可能被记录两
    次
*/
#include <bits/stdc++.h>
using namespace std;
/****************************线段树基础模板*********************************/
const int maxn=8000+5;

#define lson i*2, l, m
#define rson i*2+1, m+1, r
int color[maxn];//用来存放每种颜色的节点数的数组
int sum[maxn];
struct Segtree{

    int setv[maxn<<2];//记录以每个节点为根节点的线段的颜色

    void PushDown(int i)
    {
        if(setv[i]!=-1){
            setv[i*2]=setv[i*2+1]=setv[i];
            setv[i]=-1;
        }
    }

    void build(int i,int l,int r)
    {
        // cout<<l<<" "<<r<<endl;
        setv[i]=-1;//将每个节点都初始化为-1也就是什么颜色都没有
        if(l==r)
            return ;
        int m=(l+r)>>1;
        build(lson);
        build(rson);
    }
    void query(int ql,int qr,int i,int l,int r)
    {
        if(l==r){
            sum[l]=setv[i];
            return ;
        }
        PushDown(i);
        int m=(l+r)>>1;
        if(ql<=m)query(ql,qr,lson);
        if(m<qr)query(ql,qr,rson);
    }

    void update(int ql,int qr,int val,int i,int l,int r)
    {
        if(ql<=l&&r<=qr)
        {
            setv[i]=val;//更新这个节点的值
            return ;
        }
        PushDown(i);//先向下更新
        int m=(l+r)>>1;
        if(ql<=m) update(ql,qr,val,lson);
        if(m<qr) update(ql,qr,val,rson);
    }
};
Segtree segtree;
/****************************线段树基础模板*********************************/
int l,r,c;
int n;
void init(){
    memset(color,0,sizeof color);
    memset(sum,-1,sizeof sum);
}
int main(){
    freopen("test","r",stdin);
    while(scanf("%d",&n)!=EOF){
        init();
        segtree.build(1,1,maxn-1);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&l,&r,&c);
            segtree.update(l+1,r,c,1,1,maxn-1);
        }
        segtree.query(1,maxn-1,1,1,maxn-1);
        // for(int i=0;i<=4;i++){
        //     cout<<sum[i]<<" ";
        // }cout<<endl;
        for(int i=1;i<maxn;i++){
            while(i!=0&&sum[i]!=-1&&sum[i]==sum[i-1])//跑完连续的区间
                i++;  
            color[sum[i]]++;
        }
        for(int i=0;i<maxn;i++){
            if(color[i]>0){
                printf("%d %d\n",i,color[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

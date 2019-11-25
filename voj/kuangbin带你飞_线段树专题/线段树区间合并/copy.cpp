/*
HDU 1540 Tunnel Warfare
题义是对于一段线段，D x 表示破坏x点，
R 表示回复最近一次被破坏的点，Q x表示
询问以x点为中心的两头的最长的连续区间。

*/


#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=50050;
struct Node {
    int l,r;
    int ll,rl,ml;
    //左边开始连续的最大长度和右边开始最大的连续长度
    //以及这个区间最大连续长度
}segTree[MAXN*3];
void Build(int i,int l,int r) {
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].ll=segTree[i].rl=segTree[i].ml=r-l+1;
    if(l==r)return;
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build((i<<1)|1,mid+1,r);
}
void update(int i,int t,int val) {
    if(segTree[i].l==segTree[i].r) {
        if(val==1)segTree[i].ll=segTree[i].rl=segTree[i].ml=1;
        else segTree[i].ll=segTree[i].rl=segTree[i].ml=0;
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(t<=mid)update(i<<1,t,val);
    else update((i<<1)|1,t,val);
    segTree[i].ll=segTree[i<<1].ll;
    segTree[i].rl=segTree[(i<<1)|1].rl;
    segTree[i].ml=max(segTree[i<<1].ml,segTree[(i<<1)|1].ml);
    segTree[i].ml=max(segTree[i].ml,segTree[i<<1].rl+segTree[(i<<1)|1].ll);

    if(segTree[i<<1].ll==segTree[i<<1].r-segTree[i<<1].l+1)segTree[i].ll+=segTree[(i<<1)|1].ll;
    if(segTree[(i<<1)|1].rl==segTree[(i<<1)|1].r-segTree[(i<<1)|1].l+1)
        segTree[i].rl+=segTree[i<<1].rl;
}
int query(int i,int t) {
    if(segTree[i].l==segTree[i].r||segTree[i].ml==0||segTree[i].ml==segTree[i].r-segTree[i].l+1) {
        return segTree[i].ml;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(t<=mid) {
        if(t>=segTree[i<<1].r-segTree[i<<1].rl+1)
           return query(i<<1,t)+query((i<<1)|1,mid+1);
        else return query(i<<1,t);
    } else {
        if(t<=segTree[(i<<1)|1].l+segTree[(i<<1)|1].ll-1)
           return query((i<<1)|1,t)+query(i<<1,mid);
        else return query((i<<1)|1,t);
    }
}
int que[MAXN];
int top;
int main()
{	
	freopen("test", "r", stdin);
    int n,m;
    char str[10];
    int x;
    while(scanf("%d%d",&n,&m)!=EOF) {
        Build(1,1,n);
        top=0;
        while(m--) {
            scanf("%s", str);
            if(str[0]=='D') {
                scanf("%d",&x);
                que[top++]=x;

                update(1,x,0);


            }
            else if(str[0]=='Q') {
                scanf("%d",&x);
                printf("%d\n",query(1,x));
            } else {
                if(x>0) {
                    x=que[--top];
                    update(1,x,1);
                }
            }
        }
    }
    return 0;
}

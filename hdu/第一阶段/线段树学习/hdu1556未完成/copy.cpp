/*对一段区间改变值 区间询问值*/

#include<stdio.h>

#include<string.h>
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1

using namespace std;

int output[100000<<2];//这里表示对叶子的涂色次数进行统计的数组.

int tree[100000<<2];

int cont;

void pushdown(int rt)//向下维护数组（用处很大 在下边函数里边进行解释）{
    tree[rt*2]+=tree[rt];
    tree[rt*2+1]+=tree[rt];
}

void build( int l ,int r , int rt )//建树. {
    if( l == r ) {
        tree[rt]=0;
        return ;
    } else {
        int m = (l+r)>>1 ;
        build(lson) ;
        build(rson) ;
    }
}

void query(int L,int R,int l,int r,int rt) {
     if(L<=l&&r<=R)//区间加1.//在sum操作里边会有pushdown的操作来维护线段树的数据.（这个步骤非常重要 也非常的巧妙）
     {
         tree[rt]++;//直接涂一个区间
         return ;
     } else {
         int m=(l+r)/2;
         if(L<=m)query(L,R,lson);
         if(m<R) query(L,R,rson);
     }
}

void sum(int l,int r,int rt) {
    if(l==r) {
        output[cont]=tree[rt];//保存数据并且直接输出~.
        cont++;
        return ;
    }
    int m=(l+r)/2;
    pushdown(rt);//因为在区间上加的1，同时就要在子树上也+1....（多想想 很容易理解）
    sum(lson);
    sum(rson);
}

int main() {
    freopen("test", "r", stdin);
    int n;
    while(~scanf("%d",&n)) {
        memset(tree,0,sizeof(tree));
        if(n==0)break;
        build(1,n,1);

        int x,y;

        for(int i=0;i<n;i++) {
            scanf("%d%d",&x,&y);
            query(x,y,1,n,1);
        }

        cont=0;
        sum(1,n,1);
        for(int i=0;i<cont;i++) {
            if(i==cont-1)
	            printf("%d\n",output[i]);
            else
	            printf("%d ",output[i]);
        }
    }
}


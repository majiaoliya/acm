#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mid(a,b) ((a+b)>>1)
#define LL int
#define maxn 110000
#define IN freopen("in.txt","r",stdin);
using namespace std;

char is_prime[maxn*100];
void sieve()
{
    int m=(int)sqrt((maxn*100)+0.5);
    fill(is_prime,is_prime+(maxn*100),1);
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i<=m;i++) if(is_prime[i])
        for(int j=i*i;j<(maxn*100);j+=i) is_prime[j]=0;
}

int n,q;
LL num[maxn];
struct Tree
{
    int left,right;
    LL sum;
    LL val,lazy;
}tree[maxn<<2];

/*递归建树*/
void build(int i,int left,int right)
{
    tree[i].left=left;
    tree[i].right=right;
    tree[i].lazy=0;

    if(left==right){
        tree[i].val=num[left];
        tree[i].sum=(is_prime[num[left]]? 1:0);
        return ;
    }

    int mid=mid(left,right);

    build(i<<1,left,mid);
    build(i<<1|1,mid+1,right);

    tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
}

/*区间修改，标记下传：每当访问到当前结点的子节点时，下传标记*/
void pushdown(int i)
{
    if(tree[i].lazy){
        int tmp = (is_prime[tree[i].lazy]? 1:0);
        tree[i<<1].val=tree[i].lazy;
        tree[i<<1|1].val=tree[i].lazy;
        tree[i<<1].lazy=tree[i].lazy;
        tree[i<<1|1].lazy=tree[i].lazy;
        tree[i<<1].sum=(tree[i<<1].right-tree[i<<1].left+1)*tmp;
        tree[i<<1|1].sum=(tree[i<<1|1].right-tree[i<<1|1].left+1)*tmp;
        tree[i].lazy=0; /*下传后清零*/
    }
}

/*区间修改，d为改变量*/
void update(int i,int left,int right,LL d)
{
    if(tree[i].left==left&&tree[i].right==right)
    {
        int tmp = (is_prime[d]? 1:0);
        tree[i].sum=(right-left+1)*tmp;
        tree[i].val=d;
        tree[i].lazy=d;
        return ;
    }

    pushdown(i);

    int mid=mid(tree[i].left,tree[i].right);

    if(right<=mid) update(i<<1,left,right,d);
    else if(left>mid) update(i<<1|1,left,right,d);
    else
    {
        update(i<<1,left,mid,d);
        update(i<<1|1,mid+1,right,d);
    }

    tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
}

/*单点修改，d为改变量*/
void update(int i,int x,LL d)
{
    if(tree[i].left==tree[i].right){
        tree[i].val+=d;
        tree[i].sum=(is_prime[tree[i].val]? 1:0);
        return;
    }

    pushdown(i);
    int mid=mid(tree[i].left,tree[i].right);

    if(x<=mid) update(i<<1,x,d);
    else update(i<<1|1,x,d);

    tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
}

/*区间结果查询*/
LL query(int i,int left,int right)
{
    if(tree[i].left==left&&tree[i].right==right)
        return tree[i].sum;

    pushdown(i);

    int mid=mid(tree[i].left,tree[i].right);

    if(right<=mid) return query(i<<1,left,right);
    else if(left>mid) return query(i<<1|1,left,right);
    else return query(i<<1,left,mid)+query(i<<1|1,mid+1,right);
}


int main(int argc, char const *argv[])
{
    //IN;
	freopen("test", "r", stdin);
    sieve();
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&num[i]);
        build(1,1,n);

        while(q--)
        {
            char c;
            while(c=getchar()){
                if(c=='A'||c=='R'||c=='Q') break;
            }
            if(c=='A'){
                int v,l;
                scanf("%d %d",&v,&l);
                update(1,l,v);
            }
            if(c=='R'){
                int a,l,r;
                scanf("%d %d %d",&a,&l,&r);
                update(1,l,r,a);
            }
            if(c=='Q'){
                int l,r;
                scanf("%d %d",&l,&r);
                printf("%d\n", query(1,l,r));
            }
        }
    }

    return 0;
}

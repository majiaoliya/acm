//#include <iostream>
//#include <algorithm>
//#define MAXN 1000
//using namespace std;

//int arr[] = {1, 3, 5, 7, 9, 11};
//int size = 6;

//struct Node {
//	int start, end, sum, min;
//} tree[MAXN<<2];

//void build_tree(int node, int start, int end) {
//	tree[node].start = start, tree[node].end = end;
//	if(start == end) {
//		tree[node].sum = arr[start];
//		tree[node].min = arr[start];
//		return ;
//	}
//	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
//	build_tree(left_node, start, mid);
//	build_tree(right_node, mid+1, end);
//	tree[node].sum = tree[left_node].sum + tree[right_node].sum;
//	tree[node].min = min(tree[left_node].min, tree[right_node].min);
//}

//void update_tree(int node, int start, int end, int idx, int val) {
//	if(start == end) {
//		tree[node].sum = arr[idx] = val;
//		tree[node].min = arr[idx];
//		return ;
//	}
//	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
//	if(idx<=mid)
//		update_tree(left_node, start, mid, idx, val);
//	else
//		update_tree(right_node, mid+1, end, idx, val);
//	tree[node].sum = tree[left_node].sum + tree[right_node].sum;
//	tree[node].min = min(tree[left_node].min, tree[right_node].min);
//}

////int query_min(int node, int start, int end, int l, int r, int t) {
////	printf("%d [%d, %d]\n", t, start, end);
////	if(start == end) return tree[node].min;
////	if(start>=l && end<=r) return tree[node].min;
////	if(start>r || end<l) return 0x7fffffff;
////	else {
////		int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
////		int tl = 0x7fffffff, tr = 0x7fffffff;
////		if(l<mid)
////			tl = query_min(left_node, start, mid, l, r, -1);
////		if(mid<r)
////			tr = query_min(right_node, mid+1, end, l, r, 1);
////		return min(tr, tl);
////	}
////}

//int query_min(int node, int start, int end, int l, int r) {
//	if(start>=l && end<=r) return tree[node].min;
//	if(start == end) return tree[node].min;
//	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
//	int tl = 0x7fffffff, tr = 0x7fffffff;
//	if(mid>=left_node)
//		tl = query_min(left_node, start, mid, l, r);
//	if(mid<=r)
//		tr = query_min(right_node, mid+1, end, l, r);
//	return min(tr, tl);
//}

//int main(void) {
////	freopen("test", "r", stdin);
//	build_tree(0, 0, size-1);
//	update_tree(0, 0, size-1, 4, 6);
//	for(int i=0; i<15; i++)
//		printf("tree[%d] -- sum:%d  min:%d\n", i, tree[i].sum, tree[i].min);
//	int min = 0x7fffffff;
////	query_tree(0, 0, size-1, 0, 5, min);
//	min = query_min(0, 0, size-1, 1, 4);
//	printf("Q[%d,%d] = %d\n", 2, 4, min);

//	return 0;
//}




#include<cstdio>
#include<algorithm>
using namespace std;
struct Node
{
    int l,r,sum,Max,Min;
}Tree[1000<<2];
void PushUp(int o)
{
    Tree[o].sum = Tree[o*2].sum + Tree[o*2+1].sum;
    Tree[o].Max = max(Tree[o*2].Max,Tree[o*2+1].Max);
    Tree[o].Min = min(Tree[o*2].Min,Tree[o*2+1].Min);
}
void Build(int o,int l,int r)
{
    //首先记录l和r的值 
    Tree[o].l = l;
    Tree[o].r = r;
    if (l == r)     //到达最底层，递归终止
    {
        int t;
        scanf ("%d",&t);        //输入数据 
        Tree[o].sum = Tree[o].Max = Tree[o].Min = t;        //更新节点数据 
        return;
    }
    int mid = (l+r) >> 1;       //找到中间节点 
    Build(o*2 , l , mid);       //递归建左子树 
    Build(o*2+1 , mid+1 , r);       //递归建右子树 
    PushUp(o);      //更新当前节点的值 
}
void UpDate(int o,int l,int r,int x,int y)      //把x节点更新为y
{
    if (l == r)     //递归结束
    {
        Tree[o].Max = Tree[o].Min = Tree[o].sum = y;        //精确找到了节点，更新 
        return;
    }
    int mid = (l+r) / 2;        //找到中间位置
    if (x <= mid)
        UpDate(o*2,l,mid,x,y);      //找左子树 
    else
        UpDate(o*2+1,mid+1,r,x,y);      //找右子树 
    PushUp(o);      //更新当前节点 
}
int QuerySum(int o,int l,int r,int x,int y)     //查找x到y的和 
{
    if (l == x && r == y)       //如果恰好是当前节点，就返回 
    {
        return Tree[o].sum;
    }
    int mid = (l + r) / 2;
    if (mid >= y)       //全在左边 
        return QuerySum(o*2,l,mid,x,y);
    else if (x > mid)       //全在右边 
        return QuerySum(o*2+1,mid+1,r,x,y);
    else        //一半在左一半在右 
        return QuerySum(o*2,l,mid,x,mid) + QuerySum(o*2+1,mid+1,r,mid+1,y);//取他们的和 
}
int QueryMax(int o,int l,int r,int x,int y)//x,y表示要查询的区间
{
    if(l==x&&r==y)
    {
        return Tree[o].Max;
    }
    int mid=(l+r)/2;
    if(x>mid)
    return QueryMax(o*2+1,mid+1,r,x,y);//全在右边 
    else if(y<=mid)
    return QueryMax(o*2,l,mid,x,y);//全在左边 
    else
    return max(QueryMax(o*2,l,mid,x,mid),QueryMax(o*2+1,mid+1,r,mid+1,y));//在左右两边，取其中的最大值 
}
int  QueryMin(int o,int l,int r,int x,int y)//x,y表示要查询的区间 
{
    if(l==x&&r==y)
    {
        return Tree[o].Min;
    }
    int mid=(l+r)/2;
    if(x>mid)
   		return QueryMin(o*2+1,mid+1,r,x,y);//全在右边 
    else if(y<=mid)
    	return QueryMin(o*2,l,mid,x,y);//全在左边 
    else
    	return min(QueryMin(o*2,l,mid,x,mid),QueryMin(o*2+1,mid+1,r,mid+1,y));//在左右两边，取其中的最小值
 } 
int main()
{
    int n;
    scanf ("%d",&n);
    Build(1,1,n);
    UpDate(1, 1, n, 5, 6);
    for(int i=1; i<15; i++)
		printf("tree[%d] sum:%d max:%d min:%d\n", i, 
			QuerySum(1, 1, n, 1, n), 
			Tree[i].Max,
			Tree[i].Min);
    return 0;
}

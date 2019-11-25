#include <iostream>
#include <string.h>
#define MAXN 200000
using namespace std;

struct Node {
	int start, end, sum, max, min;
} tree[MAXN<<2+7];

//int arr[MAXN] = {1, 3, 5, 7, 9, 11};
//int arr[MAXN] = {1, 2, 3, 4, 5};
//int size = 5;
int* arr = new int[MAXN+7];
int n, m;

void build_tree(int node, int start, int end) {
	tree[node].start = start, tree[node].end = end;
	if(start == end) {
		tree[node].sum = tree[node].max = tree[node].min = arr[start];
		return ;
	}
	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
	build_tree(left_node, start, mid);
	build_tree(right_node, mid+1, end);
	tree[node].sum = tree[left_node].sum + tree[right_node].sum;
	tree[node].max = max(tree[left_node].max, tree[right_node].max);
	tree[node].min = min(tree[left_node].min, tree[right_node].min);
}

void update_tree(int node, int start, int end, int idx, int val) {
	if(start == end) {
		tree[node].sum = tree[node].max = tree[node].min = arr[idx] = val;
		return ;
	}
	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
	if(idx <= mid) //left
		update_tree(left_node, start, mid, idx, val);
	else //right
		update_tree(right_node, mid+1, end, idx, val);
	tree[node].sum = tree[left_node].sum + tree[right_node].sum;
	tree[node].max = max(tree[left_node].max, tree[right_node].max);
	tree[node].min = min(tree[left_node].min, tree[right_node].min);
}

int query_sum(int node, int start, int end, int l, int r) {
	if(start == end) return tree[node].sum;
	if(start>=l && end<=r) return tree[node].sum;
	if(start>r || end<l) return 0;
	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
	if(mid >= r) //全在左边[0, 1, 2, mid, 4, 5] 里的 [0, 1, 2];
		return query_sum(left_node, start, mid, l, r);
	else if(mid < l) //全在右边[0, 1, 2, mid, 4, 5] 里的 [4, 5];
		return query_sum(right_node, mid+1, end, l, r);
	else //一半在left一半在right
		return query_sum(left_node, start, mid, l, r) + query_sum(right_node, mid+1, end, l, r);
}

int query_max(int node, int start, int end, int l, int r) {
	if(start == end) return tree[node].max;
	if(start>=l && end<=r) return tree[node].max;
	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
	if(mid>=r)
		return query_max(left_node, start, mid, l, r);
	else if(mid<l)
		return query_max(right_node, mid+1, end, l, r);
	else
		return max(query_max(left_node, start, mid, l, r), query_max(right_node, mid+1, end, l, r));
}

int query_min(int node, int start, int end, int l, int r) {
	if(start == end) return tree[node].min;
	if(start>=l && end<=r) return tree[node].min;
	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
	if(r<=mid)
		return query_min(left_node, start, mid, l, r);
	else if(mid<l)
		return query_min(right_node, mid+1, end, l, r);
	else
		return min(query_min(left_node, start, mid, l, r), query_min(right_node, mid+1, end, l, r));
}

int main(void) {

//	build_tree(0, 0, size-1);
////	update_tree(0, 0, size-1, 0, 4);
//	for(int i=0; i<15; i++)
//		printf("tree[%d] sum:%d max:%d min:%d\n", i, 
//			tree[i].sum, 
//			tree[i].max,
//			tree[i].min);
//	printf("Q [%d,%d] = %d\n", 0, 4, query_max(0, 0, size-1, 0, 4));
//	update_tree(0, 0, size-1, 2, 6);
//	for(int i=0; i<15; i++)
//		printf("tree[%d] sum:%d max:%d min:%d\n", i, 
//			tree[i].sum, 
//			tree[i].max,
//			tree[i].min);
//	printf("Q [%d,%d] = %d\n", 2, 3, query_max(0, 0, size-1, 2, 3));

	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		for(int i=0; i<n; i++)
			scanf("%d", arr+i);
		build_tree(0, 0, n-1);
		for(int i=0; i<m; i++) {
			char buf[8];
			scanf("%s", buf);
			if(strcmp(buf, "Q") == 0) {
				int l, r;
				scanf("%d %d", &l, &r);
	//			printf("Q %d %d = %d\n", l, r, query_max(0, 0, n-1, l-1, r-1));
				printf("%d\n", query_max(0, 0, n-1, l-1, r-1));
			} else {
				int idx, val;
				scanf("%d %d", &idx, &val);
	//			printf("U %d %d\n", idx-1, val);
				update_tree(0, 0, n-1, idx-1, val);
			}
		}

	}
}

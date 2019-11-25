#include <iostream>
#include <string.h>
#define MAXN 50005
#define MAXRS 0
using namespace std;

int arr[MAXN];
int tree[MAXN<<2]; //开4maxn的树

int n, m, rs;

void build_tree(int node, int start, int end) {
	if(start == end) {
		tree[node] = arr[start];
		return ;
	}
	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
	build_tree(left_node, start, mid);
	build_tree(right_node, mid+1, end);
	tree[node] = tree[left_node] + tree[right_node];
}

/*
 * 更新  arr[idx] = val
 */
void update_tree(int node, int start, int end, int idx, int val) {
	if(start == end) {
		tree[node] = arr[idx] = val;
		return ;
	}
	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
	if(idx<=mid)
		update_tree(left_node, start, mid, idx, val);
	else 
		update_tree(right_node, mid+1, end, idx, val);
	tree[node] = tree[left_node] + tree[right_node];
}

/*
 * 查询[l,r]区间的和
 */
int query_tree(int node, int start, int end, int l, int r) {
	if(start == end) {
		if(rs < tree[node]) rs = tree[node];
		return tree[node];
	} else if(start>r || end<l) return 0;
	else if(start>=l && end<=r) return tree[node]; //树在[l,r]区间里
	int mid = (start+end)/2, left_node = 2*node+1, right_node = 2*node+2;
	int sum_left = query_tree(left_node, start, mid, l, r);
	int sum_right = query_tree(right_node, mid+1, end, l, r);
	return sum_left + sum_right;
}

int main(void) {
	
	freopen("test", "r", stdin);
//	build_tree(0, 0, 5);
//	update_tree(0, 0, 5, 4, 6);
//	for(int i=0; i<15; i++) {
//		printf("%d,", tree[i]);
//	}
//	printf("\n%d\n", query_tree(0, 0, 5, 2, 5));
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	build_tree(0, 0, n-1);
	for(int i=0; i<m; i++) {
		char c[8];
		scanf("%s", c);
		if(strcmp("U", c) == 0) {
			int idx, val;
			scanf("%d %d", &idx, &val);
			update_tree(0, 0, n-1, idx, val);
		} else if(strcmp("Q", c) == 0) {
			int l, r;
			scanf("%d %d", &l, &r);
			int t = query_tree(0, 0, n-1, l, r);
			printf("%d\n", rs);
			rs = 0;
		}
	}
	return 0;
}

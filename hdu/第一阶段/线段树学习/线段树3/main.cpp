#include <iostream>
#include <algorithm>
#define MAXN 1000
using namespace std;

int arr[] = {1, 3, 5, 7, 9, 11};
int size = 6;
int tree[MAXN] = {0};

void build_tree(int node, int start, int end) {
	if(start == end) {
		tree[node] = arr[start];
		return ;
	}	
	int mid = (start+end) / 2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;

	build_tree(left_node, start, mid);
	build_tree(right_node, mid+1, end);
	tree[node] = tree[left_node] + tree[right_node];
}

void update_tree(int node, int start, int end, int idx, int value) {
	if(start == end) {
		arr[idx] = value;
		tree[node] = arr[idx];
		return ;
	}
	
	int mid = (start+end)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	if(idx<=mid)
		update_tree(left_node, start, mid, idx, value);
	else
		update_tree(right_node, mid+1, end, idx, value);
	tree[node] = tree[left_node] + tree[right_node];
}

int query_tree(int node, int start, int end, int l, int r) {
	if(start == end) return tree[node];
	else if(start>r || end<l) return 0;
	else if(start>=l && end<=r) return tree[node];
	int mid = (start+end)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	int sum_left = query_tree(left_node, start, mid, l, r);
	int sum_right = query_tree(right_node, mid+1, end, l, r);
	return sum_left + sum_right;
}

int main(void) {
//	freopen("test", "r", stdin);
	
	build_tree(0, 0, size-1);
	update_tree(0, 0, size-1, 4, 6);
	for(int i=0; i<15; i++)
		printf("%d,", tree[i]);
	printf("\n[%d,%d] = %d\n", 2, 5, query_tree(0, 0, size-1, 2, 5));
	return 0;
}

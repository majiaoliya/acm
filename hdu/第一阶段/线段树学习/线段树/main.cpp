#include <iostream>
#include <algorithm>
#define MAXN 1000
using namespace std;

void build_tree(int arr[], int tree[], int node, int start, int end) {
	if(start == end) { //到叶子
		tree[node] = arr[start];
		return ; 
	}
	int mid = (start+end)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	build_tree(arr, tree, left_node, start, mid); //建立left
	build_tree(arr, tree, right_node, mid+1, end); //建立right
	tree[node] = tree[left_node] + tree[right_node]; //填根!!
}

void update_tree(int arr[], int tree[], int node,
	 int start, int end, int idx, int value) { //把arr[idx]改为value
	
	if(start == end) {
		arr[idx] = value;
		tree[node] = value;
		return ;
	}
	
	int mid = (start+end)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	if(idx>=start && idx<=mid) { //left
		update_tree(arr, tree, left_node, start, mid, idx, value);
	} else {
		update_tree(arr, tree, right_node, mid+1, end, idx, value);
	}
	tree[node] = tree[left_node] + tree[right_node];
}

int query_tree(int arr[], int tree[], int node,
	 int start, int end, int l, int r) { //查询[l-r]的和
	if(start>r || end<l) { //不在范围内 return 0
		return 0;
	} else if(start == end) { //到叶子
		return tree[node];
	} else if(l<=start && end<=r) { //[3-5]在[l-r]之间 (树在[l,r]区间里)
		return tree[node];
	}
	int mid = (start+end)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	int sum_left = query_tree(arr, tree, left_node, start, mid, l, r);
	int sum_right = query_tree(arr, tree, right_node, mid+1, end, l, r);
	return sum_left + sum_right; 
}

int main(void) {
//	freopen("test", "r", stdin);
	
	int arr[] = {1, 3, 5, 7, 9, 11};
	int size = 6;
	int tree[MAXN] = {0};
	
	build_tree(arr, tree, 0, 0, size-1);
	for(int i=0; i<15; i++) {
		printf("tree[%d] = %d\n", i, tree[i]);
	}
	printf("\n");
	update_tree(arr, tree, 0, 0, size-1, 4, 6);
	for(int i=0; i<15; i++) {
		printf("tree[%d] = %d\n", i, tree[i]);
	}
	
	printf("[%d, %d] = %d\n", 2, 5, query_tree(arr, tree, 0, 0, size-1, 2, 5));
	
	return 0;
}

#include <iostream>
#define MAX_LEN 1000
using namespace std;

void build_tree(int arr[], int tree[], int node, int start, int end) {
	if(start == end) {
		tree[node] = arr[start];
	} else {
		int left_node = node*2+1; //left
		int right_node = node*2+2; //right
		int mid = (start+end)/2; //中间值
		build_tree(arr, tree, left_node, start, mid);
		build_tree(arr, tree, right_node, mid+1, end);
		tree[node] = tree[left_node] + tree[right_node];
	}
}

void update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val) {
	if(start == end) {
		tree[idx] = val;
	} else {
		int mid = (start + end) / 2;
		int left_node = node*2+1;
		int right_node = node*2+2;
		
	}
}

int main(void) {
	int arr[] = {1, 3, 5, 7, 9, 11};
	int size = 6;
	
	int tree[MAX_LEN] = {0}; 
	build_tree(arr, tree, 0, 0, size-1);
	for(int i=0; i<15; i++) {
		printf("tree[%d] = %d\n", i, tree[i]);
	}
	return 0;
}

#include <iostream>
#include <string.h>
#define MAXN 50005
using namespace std;

int arr[MAXN];
int tree[MAXN<<2];

int n, m, tmax;

void build_tree(int node, int start, int end) {
	if(tmax < node) tmax = node;
	if(start == end) {
		tree[node] = arr[start];
		return ;
	}
	
	int mid = (start+end)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	
	build_tree(left_node, start, mid);
	build_tree(right_node, mid+1, end);
	tree[node] = tree[left_node] + tree[right_node];
}

void update_tree(int node, int start, int end, int idx, int value) {
	int mid = (start+end)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	
	if(start == end) {
		arr[idx] = value;
		tree[node] = value;
		return ;
	}
	
	if(idx>=start && idx<=mid) { //left
		update_tree(left_node, start, mid, idx, value);
	} else {
		update_tree(right_node, mid+1, end, idx, value);
	}
	tree[node] = tree[left_node] + tree[right_node];
}

//int query_tree(int node, int start, int end, int l, int r) {
//	if(end<l || start>r) return 0;
//	else if(start == end) return tree[node];
//	else if(l<=start && end<=end) return tree[node];
//	
//	int mid = (start+end)/2;
//	int left_node = 2*node+1;
//	int right_node = 2*node+2;
//	int sum_left = query_tree(left_node, start, mid, l, r);
//	int sum_right = query_tree(right_node, mid+1, end, l, r);
//	return sum_left + sum_right;
//}
int query_tree(int node, int start, int end, int l, int r) { //查询[l-r]的和
//	printf("%d\n", node);
	if(start>r || end<l) { //不在范围内 return 0
		return 0;
	} else if(start == end) { //到叶子
		return tree[node];
	} else if(l<=start && end<=r) { //[3-5]在[l-r]之间
		return tree[node];
	}
	int mid = (start+end)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	int sum_left = query_tree(left_node, start, mid, l, r);
	int sum_right = query_tree(right_node, mid+1, end, l, r);
	return sum_left + sum_right; 
}

int main(void) {
	
	freopen("test", "r", stdin);
	int t;
	int count = 1;
	scanf("%d", &t);
	for( ; t--; ) {	
		scanf("%d", &n);
		for(int i=0; i<n; i++) 
			scanf("%d", arr+i);
		build_tree(0, 0, n-1);
//		for(int i=0; i<=tmax; i++) {
//			printf("tree[%d] = %d\n", i, tree[i]);
//		}
//		printf("\n");
//		update_tree(0, 0, n-1, 8, 10);
//		printf("[%d, %d] = %d\n", 0, 2, query_tree(0, 0, n-1, 0, 2));
		char buf[512];
		printf("Case %d:\n", count++);
		while(EOF != scanf("%s", buf)) {
			if(strcmp(buf, "End") == 0) { break; }
			else if(0 == strcmp(buf, "Query")) {
				int l, r;
				scanf("%d %d", &l, &r);
				printf("%d\n", query_tree(0, 0, n-1, l-1, r-1));
			} else if(0 == strcmp(buf, "Add")) {
				int idx, value;
				scanf("%d %d", &idx, &value);
				update_tree(0, 0, n-1, idx-1, arr[idx-1]+value);
			} else if(0 == strcmp(buf, "Sub")) {
				int idx, value;
				scanf("%d %d", &idx, &value);
				update_tree(0, 0, n-1, idx-1, arr[idx-1]-value);
			}
		}
		
	}
	
	return 0;
}
